#pragma once
#include "Tile.h"
#include "Types.h"
#include <vector>
#include <raylib.h>

class Map
{
public:
    Map() {};

    void Initialize(Size2D MapSize);
    void Render();

    int GetWidth() const { return MapSize.Width; }
    int GetHeight() const { return MapSize.Height; }

    Rectangle GetMapBounds() const;

private:
    Size2D MapSize;
    std::vector<std::vector<Tile>> Tiles;
};