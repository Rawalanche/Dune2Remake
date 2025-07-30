#pragma once

#include "Types.h"
#include <raylib.h>

class Game;

class Viewport
{
public:
    Viewport() {};
    void Initialize();
    void Update();
    void StartCameraPan(Vector2 InitalMousePos);
    void EndCameraPan();

    bool GetIsPanning() { return IsPanning; }

    const Camera2D& GetCamera() const { return Camera; }

    Rectangle CameraMapBounds;
private:
    const Game* GameInstance = nullptr;

    bool IsPanning;
    Vector2 InitialMousePos;
    Camera2D Camera;

    void PanCamera();
    Rectangle CalculateCameraMapBounds(const Rectangle& MapBounds);
    Vector2 GetMapConstrainedCameraTarget(Vector2 CameraTarget);
};