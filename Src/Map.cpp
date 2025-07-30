#include "Map.h"
#include "Game.h"
#include <algorithm>

void Map::Render()
{
    int TileSize = Tile::TileSize;

    for (int y = 0; y < MapSize.Height; ++y)
    {
        for (int x = 0; x < MapSize.Width; ++x)
        {
            Tile& Tile = Tiles[y][x];
            DrawRectangle(x * TileSize, y * TileSize, TileSize, TileSize, Tile.TileColor);
            Color OutlineColor = ColorLerp(Tile.TileColor, BLACK, 0.1);
            DrawRectangleLines(x * TileSize, y * TileSize, TileSize, TileSize, OutlineColor);
        }
    }
    DrawRectangleLinesEx(GetMapBounds(), 5.f, RED);
    DrawRectangleLinesEx(Game::GetInstance()->Viewport.CameraMapBounds, 5.f, GREEN);
}

Rectangle Map::GetMapBounds() const
{
    int TileSize = Tile::TileSize;
    return Rectangle(0.f, 0.f, MapSize.Width * TileSize, MapSize.Height * TileSize);
}

void Map::Initialize(Size2D InMapSize)
{
    MapSize = InMapSize;
    Tiles.resize(MapSize.Height, std::vector<Tile>(MapSize.Width, Tile()));
}
