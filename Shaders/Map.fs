#version 330 core

in vec2 fragTexCoord;
out vec4 FinalColor;

uniform vec2 MapSize;
uniform sampler2D MapTexture;
uniform sampler2D SandTileTexture;
uniform sampler2D SandTileNormalTexture;
uniform sampler2D RockTileTexture;
uniform sampler2D RockTileNormalTexture;

void main()
{
    vec2 MapUV = fragTexCoord / MapSize;
    vec4 RockMask = texture(MapTexture, MapUV);

    vec4 SandSample = texture(SandTileTexture, fragTexCoord);
    vec3 SandNormal = normalize(texture(SandTileNormalTexture, fragTexCoord).rgb * 2.0 - 1.0);

    vec4 RockSample = texture(RockTileTexture, fragTexCoord);
    vec3 RockNormal = normalize(texture(RockTileNormalTexture, fragTexCoord).rgb * 2.0 - 1.0);

    float Blend = clamp((RockSample.a + RockMask.g - 1.0) * 4, 0.0, 1.0);

    vec3 BlendedSample = mix(SandSample, RockSample, Blend).rgb;
    vec3 BlendedNormal = normalize(mix(SandNormal, RockNormal, Blend));

    vec3 LightDirection = normalize(vec3(-1.0, 1.0, 0.5));
    vec3 AmbientLight = vec3(0.4, 0.5, 0.6);
    vec3 DirectLight = vec3((max(dot(BlendedNormal, LightDirection), 0.0))) * vec3(1.0,0.9,0.8);
    vec3 Light = AmbientLight + DirectLight;

    FinalColor = vec4(BlendedSample * Light, 1.0);
}