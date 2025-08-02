#include "Tile.h"
#include <raymath.h>

Texture2D Tile::DummyTexture = {};
Texture2D Tile::SandTileTexture = {};
Texture2D Tile::SandTileNormalTexture = {};
Texture2D Tile::RockTileTexture = {};
Texture2D Tile::RockTileNormalTexture = {};
Texture2D Tile::CliffTileTexture = {};
Texture2D Tile::CliffTileNormalTexture = {};

void Tile::Initialize()
{
    DummyTexture = LoadTextureFromImage(GenImageColor(TileSize, TileSize, WHITE));

    SandTileTexture = LoadTexture("Assets/Tiles/Tile_Sand_BaseColor.png");
    SetTextureFilter(SandTileTexture, TEXTURE_FILTER_POINT);

    SandTileNormalTexture = LoadTexture("Assets/Tiles/Tile_Sand_Normal.png");
    SetTextureWrap(SandTileNormalTexture, TEXTURE_WRAP_REPEAT);
    SetTextureFilter(SandTileNormalTexture, TEXTURE_FILTER_BILINEAR);

    RockTileTexture = LoadTexture("Assets/Tiles/Tile_Rock_BaseColor.png");
    SetTextureWrap(RockTileTexture, TEXTURE_WRAP_REPEAT);
    SetTextureFilter(RockTileTexture, TEXTURE_FILTER_BILINEAR);

    RockTileNormalTexture = LoadTexture("Assets/Tiles/Tile_Rock_Normal.png");
    SetTextureWrap(RockTileNormalTexture, TEXTURE_WRAP_REPEAT);
    SetTextureFilter(RockTileNormalTexture, TEXTURE_FILTER_BILINEAR);

    CliffTileTexture = LoadTexture("Assets/Tiles/Tile_Cliff_BaseColor.png");
    SetTextureWrap(CliffTileTexture, TEXTURE_WRAP_REPEAT);
    SetTextureFilter(CliffTileTexture, TEXTURE_FILTER_BILINEAR);

    CliffTileNormalTexture = LoadTexture("Assets/Tiles/Tile_Cliff_Normal.png");
    SetTextureWrap(CliffTileNormalTexture, TEXTURE_WRAP_REPEAT);
    SetTextureFilter(CliffTileNormalTexture, TEXTURE_FILTER_BILINEAR);
}