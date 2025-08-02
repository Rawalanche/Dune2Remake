#pragma once
#include <raylib.h>

struct Coords
{
	int x, y;

	Coords() : x(0), y(0) {};
	Coords(int InWidth, int InHeight) : x(InWidth), y(InHeight) {}

	Vector2 ToVector2() const { return { (float)x, (float)y }; }
};