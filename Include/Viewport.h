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

private:
    bool IsPanning;
    Vector2 InitialMousePos;
    Camera2D Camera;
    const Game* GameInstance = nullptr;

    void PanCamera();
};