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
    BeginShaderMode(MapShader);

    Vector2 MapSize = GetMapSize();
    SetShaderValue(MapShader, GetShaderLocation(MapShader, "MapSize"), &MapSize, SHADER_UNIFORM_VEC2);
    SetShaderValueTexture(MapShader, GetShaderLocation(MapShader, "MapTexture"), MapTexture);
    SetShaderValueTexture(MapShader, GetShaderLocation(MapShader, "SandTileTexture"), Tile::SandTileTexture);
    SetShaderValueTexture(MapShader, GetShaderLocation(MapShader, "SandTileNormalTexture"), Tile::SandTileNormalTexture);
    SetShaderValueTexture(MapShader, GetShaderLocation(MapShader, "RockTileTexture"), Tile::RockTileTexture);
    SetShaderValueTexture(MapShader, GetShaderLocation(MapShader, "RockTileNormalTexture"), Tile::RockTileNormalTexture);
    Rectangle MapBounds = GetMapBounds();
    DrawTexturePro(Tile::DummyTexture, MapBounds, MapBounds, Vector2{ 0.0f, 0.0f }, 0.0f, WHITE);

    EndShaderMode();

    DrawRectangleLinesEx(GetMapBounds(), 5.f, Color(0, 0, 0, 128));
}

Rectangle Map::GetMapBounds() const
{
    return Rectangle(0.f, 0.f, MapImage.width * Tile::TileSize, MapImage.height * Tile::TileSize);
}