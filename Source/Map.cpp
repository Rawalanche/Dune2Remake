#include "Map.h"
#include "Game.h"
#include <algorithm>
#include "rlgl.h"
#include <raymath.h>

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
			Tile& Tile = Tiles[y][x];
			const Color& TileColor = GetImageColor(MapImage, x, y);
			const Vector2 Position = Vector2(x * Tile::TileSize, y * Tile::TileSize);

            Tile.SetPosition(Position);
			if (TileColor.g > 0)
			{
				Tile.TileType = TileType::Rock;
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
			const Tile& Tile = Tiles[y][x];
			Tile.DrawTile();
		}
	}
}

Rectangle Map::GetMapBounds() const
{
	return Rectangle(0.f, 0.f, MapImage.width * Tile::TileSize, MapImage.height * Tile::TileSize);
}