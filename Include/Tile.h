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

	TileType TileType = TileType::Sand;
	int SpiceAmount;

    Tile() {};

	static void Initialize();

    void DrawTile() const;
    void SetPosition(const Vector2& Position);
    Rectangle GetSourceDrawRectangleFromPattern(const std::string& Pattern) const;

private:
	static Texture2D SandTile;
	static Texture2D DuneTileSet;
	static Texture2D RockTileSet;
	static Texture2D CliffTileSet;
	static std::unordered_map<std::string, Vector2> TileSetCoords;

	Vector2 Position = { 0.0f, 0.0f };
	Rectangle TargetDrawRectangle{};
};