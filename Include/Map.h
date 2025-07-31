#pragma once
#include "Tile.h"
#include "Types.h"
#include <vector>
#include <raylib.h>

class Map
{
public:
    Map() {};

    void Initialize();
    void Render();

    int GetWidth() const { return MapImage.width; }
    int GetHeight() const { return MapImage.height; }

    Rectangle GetMapBounds() const;

private:
    const int TileSize = Tile::TileSize;
    std::vector<std::vector<Tile>> Tiles;
    Image MapImage;
    void GenerateMap();
};