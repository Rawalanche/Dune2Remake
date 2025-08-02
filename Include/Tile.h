#pragma once
#include "Types.h"
#include <raylib.h>
#include <unordered_map>
#include <string>

enum class TileType
{
	Sand,
	Rock,
	Cliff
};

class Tile
{
public:
	static constexpr int TileSize = 64;
	static constexpr int TileTextureSize = 16;
	static const char Directions[];

	TileType TileType = TileType::Sand;
	int SpiceAmount;

	Tile() {};

	static void Initialize();
	static std::vector<Coords> GetNeighborTileCoords(int x, int y)
	{
		return { Coords(x, y - 1), Coords(x + 1, y), Coords(x, y + 1), Coords(x - 1, y) };
	}

	void DrawTile() const;
	void SetPosition(const Vector2& Position);
	void SetTilePattern(const std::string& InPattern) { TilePattern = InPattern; }
	Rectangle GetSourceDrawRectangleFromPattern() const;

private:
	static Texture2D SandTile;
	static Texture2D DuneTileSet;
	static Texture2D RockTileSet;
	static Texture2D CliffTileSet;
	static std::unordered_map<std::string, Vector2> TileSetCoords;

	std::string TilePattern{};
	Vector2 Position = { 0.0f, 0.0f };
	Rectangle TargetDrawRectangle{};
};