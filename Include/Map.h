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

    Rectangle GetMapBounds() const;
    Vector2 GetMapSize() const
    {
        return Vector2
        {
            static_cast<float>(MapImage.width),
            static_cast<float>(MapImage.height)
        };
    }
private:
    std::vector<std::vector<Tile>> Tiles;
    Image MapImage;
    Texture2D MapTexture;
    Shader MapShader;
    void GenerateMap();
};