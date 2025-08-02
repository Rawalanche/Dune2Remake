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
			Tile& CurrentTile = Tiles[y][x];
			const Color& TileColor = GetImageColor(MapImage, x, y);
			const Vector2 Position = Vector2(x * Tile::TileSize, y * Tile::TileSize);

			CurrentTile.SetPosition(Position);
			if (TileColor.g > 0)
			{
				CurrentTile.TileType = TileType::Rock;
			}
			else
			{
				CurrentTile.TileType = TileType::Sand;
			}
		}
	}

	for (int y = 0; y < MapImage.height; ++y)
	{
		for (int x = 0; x < MapImage.width; ++x)
		{
			Tile& CurrentTile = Tiles[y][x];
			std::vector<Coords> NeighborTileCoords = Tile::GetNeighborTileCoords(x, y);
			std::string TilePattern{};

			for (int c = 0; c < NeighborTileCoords.size(); ++c)
			{
				Coords& NeighborCoords = NeighborTileCoords[c];

				if (!IsCoordinateInMapBounds(NeighborCoords.x, NeighborCoords.y))
				{
					continue; // Treat neighbor as the same tile (Don't append direction to Pattern)
				}

				Tile& NeighborTile = Tiles[NeighborCoords.y][NeighborCoords.x];

				if (CurrentTile.TileType != NeighborTile.TileType)
				{
					TilePattern.push_back(Tile::Directions[c]);
				}
			}
			CurrentTile.SetTilePattern(TilePattern);
		}
	}
}

void Map::Render()
{
	for (const auto& Row : Tiles)
	{
		for (const auto& Tile : Row)
		{
			Tile.DrawTile();
		}
	}
}

Rectangle Map::GetMapBounds() const
{
	return Rectangle(0.f, 0.f, MapImage.width * Tile::TileSize, MapImage.height * Tile::TileSize);
}