#include "Map.h"
#include <algorithm>

void Map::Render()
{
    for (int y = 0; y < MapSize.Height; ++y)
    {
        for (int x = 0; x < MapSize.Width; ++x)
        {
            Tile& Tile = Tiles[y][x];
            DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, Tile.TileColor);
            Color OutlineColor = ColorLerp(Tile.TileColor, BLACK, 0.1);
            DrawRectangleLines(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, OutlineColor);
        }
    }
}

void Map::Initialize(Size2D InMapSize)
{
    MapSize = InMapSize;
    Tiles.resize(MapSize.Height, std::vector<Tile>(MapSize.Width, Tile()));
}
