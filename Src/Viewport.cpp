#include "Viewport.h"
#include "Game.h"
#include <raymath.h>

void Viewport::Initialize()
{
    GameInstance = Game::GetInstance();
    Vector2 ScreenSize = GameInstance->ScreenSize.ToVector2();
    Camera.offset = { ScreenSize.x / 2.f, ScreenSize.y / 2.f };
    Camera.target = Camera.offset;
    Camera.rotation = 0.f;
    Camera.zoom = 1.0f;
}

void Viewport::Update()
{
    PanCamera();
}

void Viewport::StartCameraPan(Vector2 InInitalMousePos)
{
    InitialMousePos = InInitalMousePos;
    IsPanning = true;
}

void Viewport::EndCameraPan()
{
    IsPanning = false;
}

void Viewport::PanCamera()
{
    if (!IsPanning) { return; }

    Vector2 PanDirection = GetMousePosition() - InitialMousePos;
    Camera.target += PanDirection * GetFrameTime() * 10.f;
}
