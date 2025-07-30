#include "Viewport.h"
#include "Game.h"
#include "Tile.h"
#include <raymath.h>

void Viewport::Initialize()
{
    GameInstance = Game::GetInstance();
    Camera.offset = GameInstance->ScreenSize.ToVector2() * 0.5;
    Camera.target = Camera.offset;
    Camera.rotation = 0.f;
    Camera.zoom = 1.0f;
    CameraMapBounds = CalculateCameraMapBounds(GameInstance->Map.GetMapBounds());
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
    Vector2 DesiredCameraTarget = Camera.target + PanDirection * GetFrameTime() * 10.f;
    Camera.target = GetMapConstrainedCameraTarget(DesiredCameraTarget);
}

Rectangle Viewport::CalculateCameraMapBounds(const Rectangle& MapBounds)
{
    Vector2 ScreenSize = GameInstance->ScreenSize.ToVector2();
    return Rectangle(Camera.offset.x, Camera.offset.y, MapBounds.width - ScreenSize.x, MapBounds.height - ScreenSize.y);
}

Vector2 Viewport::GetMapConstrainedCameraTarget(Vector2 CameraTarget)
{
    Vector2 MinBounds = { CameraMapBounds.x, CameraMapBounds.y };
    Vector2 MaxBounds = { CameraMapBounds.x + CameraMapBounds.width, CameraMapBounds.y + CameraMapBounds.height };
    TraceLog(LOG_INFO, "Camera MinBounds: (%f, %f), MaxBounds: (%f, %f)", MinBounds.x, MinBounds.y, MaxBounds.x, MaxBounds.y);


    Vector2 NewTarget;
    NewTarget.x = Clamp(CameraTarget.x, CameraMapBounds.x, CameraMapBounds.x + CameraMapBounds.width);
    NewTarget.y = Clamp(CameraTarget.y, CameraMapBounds.y, CameraMapBounds.y + CameraMapBounds.height);
    return NewTarget;
}
