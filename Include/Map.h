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

	bool IsCoordinateInMapBounds(int x, int y)
	{
		return x >= 0 && y >= 0 && x < MapImage.width && y < MapImage.height;
	}

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
	void GenerateMap();
};