#include "Map.h"
#include "Game.h"
#include <algorithm>

void Map::Initialize()
{
    MapImage = LoadImage("Assets/Maps/Map_Test.png");
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
            Tile& Tile = Tiles[y][x];
            if (TileColor.g > 0)
            {
                Tile.TileType = TileType::Rock;
                TraceLog(LOG_INFO, "Tile at (%d, %d) is Ground", x, y);
            }
            else
            {
                Tile.TileType = TileType::Sand;
            }
        }
    }
}

void Map::Render()
{
    for (int y = 0; y < MapImage.height; ++y)
    {
        for (int x = 0; x < MapImage.width; ++x)
        {
            Tile& Tile = Tiles[y][x];
            Tile.DrawTile(x, y);
        }
    }
    DrawRectangleLinesEx(GetMapBounds(), 5.f, Color(0,0,0,128));
}

Rectangle Map::GetMapBounds() const
{
    return Rectangle(0.f, 0.f, MapImage.width * TileSize, MapImage.height * TileSize);
}
