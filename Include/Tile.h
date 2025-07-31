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
    static std::unordered_map<std::string, Size2D> TilePatternMap;

    Tile() {};

    static void Initialize();

    TileType TileType = TileType::Sand;
    int SpiceAmount;

    void DrawTile(int x, int y);

    const Rectangle GetTileTexture();
    const Rectangle GetTileFromPattern(const std::string& Pattern);

    static Texture2D TileSet;

};