#include "Tile.h"
#include <raymath.h>

Texture2D Tile::SandTile = {};
Texture2D Tile::SpiceLowTileSet = {};
Texture2D Tile::SpiceHighTileSet = {};
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
	SpiceLowTileSet = LoadTexture("Assets/Tiles/Tiles_SpiceLow.png");
	SpiceHighTileSet = LoadTexture("Assets/Tiles/Tiles_SpiceHigh.png");
	DuneTileSet = LoadTexture("Assets/Tiles/Tiles_Dunes.png");
	RockTileSet = LoadTexture("Assets/Tiles/Tiles_Rocks.png");
	CliffTileSet = LoadTexture("Assets/Tiles/Tiles_Cliffs.png");
}

std::unordered_set<TileType> Tile::GetCompatibleTileTypes(const TileType& Type)
{
	switch (Type)
	{
	case TileType::Sand:
		return std::unordered_set<TileType>{TileType::Sand};
		break;
	case TileType::SpiceLow:
		return std::unordered_set<TileType>{TileType::SpiceLow, TileType::SpiceHigh};
		break;
	case TileType::SpiceHigh:
		return std::unordered_set<TileType>{TileType::SpiceHigh};
		break;
	case TileType::Dune:
		return std::unordered_set<TileType>{TileType::Dune};
		break;
	case TileType::Rock:
		return std::unordered_set<TileType>{TileType::Rock, TileType::Cliff};
		break;
	case TileType::Cliff:
		return std::unordered_set<TileType>{TileType::Cliff};
		break;
	default:
		return std::unordered_set<TileType>();
		break;
	}
}

void Tile::DrawTile() const
{
	Texture2D* Texture = nullptr;

	switch (Type)
	{
		case TileType::Sand:
			Texture = &SandTile;
			break;
		case TileType::SpiceLow:
			Texture = &SpiceLowTileSet;
			break;
		case TileType::SpiceHigh:
			Texture = &SpiceHighTileSet;
			break;
		case TileType::Dune:
			Texture = &DuneTileSet;
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
	if (!TileSetCoords.contains(TilePattern) || Type == TileType::Sand)
	{
		return Rectangle(0.f, 0.f, TileTextureSize, TileTextureSize);
	}

	const Vector2 Coords = TileSetCoords[TilePattern] * TileTextureSize;
	return Rectangle(Coords.x, Coords.y, TileTextureSize, TileTextureSize);
}
