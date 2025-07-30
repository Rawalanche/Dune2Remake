#pragma once
#include <raylib.h>

struct Size2D
{
    int Width, Height;

    Size2D() : Width(0), Height(0) {};
    Size2D(int InWidth, int InHeight) : Width(InWidth), Height(InHeight) {}

    Vector2 ToVector2() const { return { (float)Width, (float)Height }; }
};