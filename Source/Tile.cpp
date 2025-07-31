#include "Tile.h"
#include <raymath.h>

Texture2D Tile::TileSet = {};
std::unordered_map<std::string, Size2D> Tile::TilePatternMap = {
    {"SSSSSSSSS", {0, 0}},
    {"SRSSRRSRS", {1, 0}},
    {"SRSRRSSRS", {2, 0}},
    {"SSSSRRSRS", {3, 0}},
    {"SSSRRSSRS", {4, 0}},
    {"SSSSRRSRR", {5, 0}},
    {"SSSRRRRRR", {6, 0}},
    {"SSSRRSRRS", {7, 0}},
    {"SSSRRRSRS", {0, 1}},
    {"SSSRRRRRS", {1, 1}},
    {"SSSRRRSRR", {2, 1}},
    {"SRSSRRSSS", {3, 1}},
    {"SRSRRSSSS", {4, 1}},
    {"SRRSRRSRR", {5, 1}},
    {"RRRRRRRRR", {6, 1}},
    {"RRSRRSRRS", {7, 1}},
    {"SRSRRRSSS", {0, 2}},
    {"RRSRRRSSS", {1, 2}},
    {"SRRRRRSSS", {2, 2}},
    {"SRSRRRSRR", {3, 2}},
    {"SRSRRRRRS", {4, 2}},
    {"SRRSRRSSS", {5, 2}},
    {"RRRRRRSSS", {6, 2}},
    {"RRSRRSSSS", {7, 2}},
    {"SSSSRSSRS", {0, 3}},
    {"SRRSRRSRS", {1, 3}},
    {"RRSRRSSRS", {2, 3}},
    {"SRRRRRSRS", {3, 3}},
    {"RRSRRRSRS", {4, 3}},
    {"RRRRRRRRS", {5, 3}},
    {"RRRRRRSRS", {6, 3}},
    {"RRRRRRSRR", {7, 3}},
    {"SRSSRSSSS", {0, 4}},
    {"SRSSRRSRR", {1, 4}},
    {"SRSRRSRRS", {2, 4}},
    {"RRSRRRSRR", {3, 4}},
    {"SRRRRRRRS", {4, 4}},
    {"RRSRRRRRS", {5, 4}},
    {"SRSRRRSRS", {6, 4}},
    {"SRRRRRSRR", {7, 4}},
    {"SRSSRSSRS", {0, 5}},
    {"SSSRRRSSS", {1, 5}},
    {"SSSSRSSSS", {2, 5}},
    {"SSSSRRSSS", {3, 5}},
    {"SSSRRSSSS", {4, 5}},
    {"RRSRRRRRR", {5, 5}},
    {"SRSRRRRRR", {6, 5}},
    {"SRRRRRRRR", {7, 5}},
};

void Tile::Initialize()
{
    TileSet = LoadTexture("Assets/Tiles/TileSet.png");
}

void Tile::DrawTile(int x, int y)
{
    DrawTextureRec(TileSet, GetTileTexture(), Vector2(x, y) * TileSize, WHITE);
}

const Rectangle Tile::GetTileTexture()
{
    switch (TileType)
    {
    case TileType::Sand:
        return GetTileFromPattern("SSSSSSSSS");
        break;
    case TileType::Rock:
        return GetTileFromPattern("RRRRRRRRR");
        break;
    default:
        return GetTileFromPattern("SSSSSSSSS");
    }
}

const Rectangle Tile::GetTileFromPattern(const std::string& Pattern)
{
    const Size2D Coords = TilePatternMap[Pattern];
    const Vector2 TopLeft = Vector2(Coords.Width, Coords.Height) * TileSize;
    return Rectangle(TopLeft.x, TopLeft.y, TopLeft.x + TileSize, TopLeft.y + TileSize);
}
