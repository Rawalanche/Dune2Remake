#include "Tile.h"
#include <raymath.h>

Texture2D Tile::SandTile = {};
Texture2D Tile::DuneTileSet = {};
Texture2D Tile::RockTileSet = {};
Texture2D Tile::CliffTileSet = {};

const char Tile::Directions[] = "NESW";

std::unordered_map<std::string, Vector2> Tile::TileSetCoords
{
	{"NW",	{0.0f, 0.0f}},
	{"N",	{1.0f, 0.0f}},
	{"NE",	{2.0f, 0.0f}},
	{"NEW",	{3.0f, 0.0f}},
	{"W",	{0.0f, 1.0f}},
	{"",	{1.0f, 1.0f}},
	{"E",	{2.0f, 1.0f}},
	{"EW",	{3.0f, 1.0f}},
	{"SW",	{0.0f, 2.0f}},
	{"S",	{1.0f, 2.0f}},
	{"ES",	{2.0f, 2.0f}},
	{"ESW",	{3.0f, 2.0f}},
	{"NSW",	{0.0f, 3.0f}},
	{"NS",	{1.0f, 3.0f}},
	{"NES",	{2.0f, 3.0f}},
	{"NESW",{3.0f, 3.0f}}
};

void Tile::Initialize()
{
	SandTile = LoadTexture("Assets/Tiles/Tile_Sand.png");
	DuneTileSet = LoadTexture("Assets/Tiles/Tiles_Dunes.png");
	RockTileSet = LoadTexture("Assets/Tiles/Tiles_Rocks.png");
	CliffTileSet = LoadTexture("Assets/Tiles/Tiles_Cliffs.png");
}

void Tile::DrawTile() const
{
	Texture2D* Texture = nullptr;

	switch (TileType)
	{
		case TileType::Sand:
			Texture = &SandTile;
			break;
		case TileType::Rock:
			Texture = &RockTileSet;
			break;
		case TileType::Cliff:
			Texture = &CliffTileSet;
			break;
		default:
			Texture = &SandTile;
			break;
	}

	Rectangle SourceRect = GetSourceDrawRectangleFromPattern();
	DrawTexturePro(*Texture, SourceRect, TargetDrawRectangle, Vector2(0.f, 0.f), 0.f, WHITE);

}

void Tile::SetPosition(const Vector2& InPosition)
{
	Position = InPosition;
	TargetDrawRectangle = Rectangle(Position.x, Position.y, TileSize, TileSize);
}

Rectangle Tile::GetSourceDrawRectangleFromPattern() const
{
	if (!TileSetCoords.contains(TilePattern) || TileType == TileType::Sand)
	{
		return Rectangle(0.f, 0.f, TileTextureSize, TileTextureSize);
	}

	const Vector2 Coords = TileSetCoords[TilePattern] * TileTextureSize;
	return Rectangle(Coords.x, Coords.y, TileTextureSize, TileTextureSize);
}
