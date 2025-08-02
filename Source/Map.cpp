#include "Map.h"
#include "Game.h"
#include <algorithm>
#include "rlgl.h"
#include <raymath.h>

void Map::Initialize()
{
    MapImage = LoadImage("Assets/Maps/Map_Test.png");
    MapTexture = LoadTextureFromImage(MapImage);
    SetTextureWrap(MapTexture, TEXTURE_WRAP_CLAMP);
    SetTextureFilter(MapTexture, TEXTURE_FILTER_BILINEAR);
    MapShader = LoadShader(nullptr, "Shaders/Map.fs");
    GenerateMap();
}


void Map::GenerateMap()
{
    Tiles.resize(MapImage.height, std::vector<Tile>(MapImage.width, Tile()));

    for (int y = 0; y < MapImage.height; ++y)
    {
        for (int x = 0; x < MapImage.width; ++x)
        {
            const Color& TileColor = GetImageColor(MapImage, x, y);
            Tile& tile = Tiles[y][x];
            if (TileColor.g > 0)
            {
                tile.TileType = TileType::Rock;
            }
            else
            {
                tile.TileType = TileType::Sand;
            }
        }
    }
}

void Map::Render()
{
    rlActiveTextureSlot(1);
    rlEnableTexture(MapTexture.id);
    rlActiveTextureSlot(2);
    rlEnableTexture(Tile::SandTileTexture.id);
    rlActiveTextureSlot(3);
    rlEnableTexture(Tile::SandTileNormalTexture.id);
    rlActiveTextureSlot(4);
    rlEnableTexture(Tile::RockTileTexture.id);
    rlActiveTextureSlot(5);
    rlEnableTexture(Tile::RockTileNormalTexture.id);
    rlActiveTextureSlot(6);
    rlEnableTexture(Tile::CliffTileTexture.id);
    rlActiveTextureSlot(7);
    rlEnableTexture(Tile::CliffTileNormalTexture.id);

    BeginShaderMode(MapShader);

    Vector2 MapSize = GetMapSize();
    SetShaderValue(MapShader, GetShaderLocation(MapShader, "MapSize"), &MapSize, SHADER_UNIFORM_VEC2);

    int slot1 = 1; SetShaderValue(MapShader, GetShaderLocation(MapShader, "MapTexture"), &slot1, SHADER_UNIFORM_INT);
    int slot2 = 2; SetShaderValue(MapShader, GetShaderLocation(MapShader, "SandTileTexture"), &slot2, SHADER_UNIFORM_INT);
    int slot3 = 3; SetShaderValue(MapShader, GetShaderLocation(MapShader, "SandTileNormalTexture"), &slot3, SHADER_UNIFORM_INT);
    int slot4 = 4; SetShaderValue(MapShader, GetShaderLocation(MapShader, "RockTileTexture"), &slot4, SHADER_UNIFORM_INT);
    int slot5 = 5; SetShaderValue(MapShader, GetShaderLocation(MapShader, "RockTileNormalTexture"), &slot5, SHADER_UNIFORM_INT);
    int slot6 = 6; SetShaderValue(MapShader, GetShaderLocation(MapShader, "CliffTileTexture"), &slot6, SHADER_UNIFORM_INT);
    int slot7 = 7; SetShaderValue(MapShader, GetShaderLocation(MapShader, "CliffTileNormalTexture"), &slot7, SHADER_UNIFORM_INT);

    DrawTexturePro(Tile::DummyTexture, GetMapBounds(), GetMapBounds(), Vector2(0, 0), 0.f, WHITE);

    EndShaderMode();

    rlActiveTextureSlot(0);
}

Rectangle Map::GetMapBounds() const
{
    return Rectangle(0.f, 0.f, MapImage.width * Tile::TileSize, MapImage.height * Tile::TileSize);
}