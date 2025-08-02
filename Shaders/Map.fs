#version 330 core

in vec2 fragTexCoord;
out vec4 FinalColor;

uniform vec2 MapSize;
uniform sampler2D MapTexture;
uniform sampler2D SandTileTexture;
uniform sampler2D SandTileNormalTexture;
uniform sampler2D RockTileTexture;
uniform sampler2D RockTileNormalTexture;
uniform sampler2D CliffTileTexture;
uniform sampler2D CliffTileNormalTexture;

void main()
{
	vec2 MapUV = fragTexCoord / MapSize;
	vec4 RockMask = texture(MapTexture, MapUV);
	vec4 RockMaskOffset = texture(MapTexture, MapUV + vec2(0.002));
	vec4 RockMaskOffsetB = texture(MapTexture, MapUV - vec2(0.002));

	vec4 SandSample = texture(SandTileTexture, fragTexCoord);
	vec3 SandNormal = normalize(texture(SandTileNormalTexture, fragTexCoord).rgb * 2.0 - 1.0);

	vec4 RockSample = texture(RockTileTexture, fragTexCoord);
	vec3 RockNormal = normalize(texture(RockTileNormalTexture, fragTexCoord).rgb * 2.0 - 1.0);

	vec4 CliffSample = texture(CliffTileTexture, fragTexCoord);
	vec3 CliffNormal = normalize(texture(CliffTileNormalTexture, fragTexCoord).rgb * 2.0 - 1.0);

	float RockBlend = clamp((RockSample.a + RockMask.g - 1.0) * 4, 0.0, 1.0);

	vec3 RockBlendColor = mix(SandSample, RockSample, RockBlend).rgb;
	vec3 RockBlendNormal = normalize(mix(SandNormal, RockNormal, RockBlend));

	float CliffBlend = clamp((CliffSample.a + RockMask.r - 1.0) * 8, 0.0, 1.0);
	float CliffShadow = clamp((CliffSample.a + RockMaskOffset.r - 1.0) * 4, 0.0, 1.0);
	float GroundShadow = clamp((CliffSample.a + RockMaskOffsetB.r - 1.0) * 4, 0.0, 1.0);

	vec3 BlendedSample = mix(RockBlendColor * ((1-GroundShadow)+0.2), CliffSample.rgb * (CliffShadow + 0.2), CliffBlend);
	vec3 BlendedNormal = normalize(mix(RockBlendNormal, CliffNormal, CliffBlend));

	vec3 LightDirection = normalize(vec3(-1.0, 1.0, 0.5));
	vec3 AmbientLight = vec3(0.1);
	vec3 DirectLight = vec3((max(dot(BlendedNormal, LightDirection), 0.0))) * vec3(1.2);
	vec3 Light = pow(AmbientLight + DirectLight, vec3(1.0/2.2));

	FinalColor = vec4(BlendedSample * Light, 1.0);
}