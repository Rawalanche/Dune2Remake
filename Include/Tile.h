#pragma once
#include <raylib.h>

enum class TileType
{
    Sand,
    Ground,
    Rock
};

struct Tile
{
    TileType Type;
    Color TileColor;
    int SpiceAmount;

    static constexpr int TileSize = 32;

    Tile(TileType Type = TileType::Sand, Color TileColor = BROWN, int SpiceAmount = 0) : Type(Type), TileColor(TileColor), SpiceAmount(SpiceAmount) {}
};