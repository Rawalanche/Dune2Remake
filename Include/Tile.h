#pragma once
#include "Types.h"
#include <raylib.h>
#include <unordered_map>
#include <string>

enum class TileType
{
    Sand,
    Rock,
    Cliff
};

class Tile
{
public:
    static constexpr int TileSize = 64;
    static Texture2D DummyTexture;
    static Texture2D SandTileTexture;
    static Texture2D SandTileNormalTexture;
    static Texture2D RockTileTexture;
    static Texture2D RockTileNormalTexture;
    static Texture2D CliffTileTexture;
    static Texture2D CliffTileNormalTexture;

    Tile() {};

    static void Initialize();

    TileType TileType = TileType::Sand;
    int SpiceAmount;
};