#pragma once
#include <raylib.h>

class Game;
class Viewport;

class InputManager
{
public:
    InputManager() {};
    void Initialize();
    void ProcessInput();

private:
    bool IsClickDragging = false;
    const float ClickDragDistance = 5.f;
    Vector2 InitialMousePosition;
    Viewport* Viewport;
    Game* Game;

    void DetectMouseButtonAction(int Button);
    void OnMouseButtonPress(int Button);
    void OnMouseButtonRelease(int Button);
    void OnMouseButtonClick(int Button);
    void OnMouseButtonClickDrag(int Button);

    bool HasClickHappend();
};