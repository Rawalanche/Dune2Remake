#pragma once
#include "Tile.h"
#include "Types.h"
#include <vector>
#include <raylib.h>

class Map
{
public:
    static const int TILE_SIZE = 32;

    Map() {};

    void Initialize(Size2D MapSize);
    void Render();

    int GetWidth() const { return MapSize.Width; }
    int GetHeight() const { return MapSize.Height; }

private:
    Size2D MapSize;
    std::vector<std::vector<Tile>> Tiles;
};