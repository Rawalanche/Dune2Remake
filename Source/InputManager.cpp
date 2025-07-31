#include "InputManager.h"
#include "Game.h"
#include <raymath.h>

void InputManager::Initialize()
{
    Game = Game::GetInstance();
    Viewport = &Game->Viewport;
}

void InputManager::ProcessInput()
{
    DetectMouseButtonAction(0);
    DetectMouseButtonAction(1);
}

void InputManager::DetectMouseButtonAction(int Button)
{
    if (IsMouseButtonPressed(Button))
    {
        InitialMousePosition = GetMousePosition();
        OnMouseButtonPress(Button);
    }

    if (IsMouseButtonDown(Button))
    {
        if (!IsClickDragging)
        {
            if (IsClickDragging = Vector2Distance(InitialMousePosition, GetMousePosition()) > ClickDragDistance)
            {
                OnMouseButtonClickDrag(Button);
            }
        }
    }

    if (IsMouseButtonReleased(Button))
    {
        if (HasClickHappend())
        {
            OnMouseButtonClick(Button);
        }
        OnMouseButtonRelease(Button);
        IsClickDragging = false;
    }
}

void InputManager::OnMouseButtonPress(int Button)
{
    TraceLog(LOG_INFO, "Pressed");
}

void InputManager::OnMouseButtonRelease(int Button)
{
    switch (Button)
    {
    case 0:
        break;
    case 1:
        Viewport->EndCameraPan();
        break;
    default:
        return;
    }
}

void InputManager::OnMouseButtonClick(int Button)
{
    TraceLog(LOG_INFO, "Clicked");
}

void InputManager::OnMouseButtonClickDrag(int Button)
{
    switch (Button)
    {
        case 0:
            break;
        case 1:
            Viewport->StartCameraPan(InitialMousePosition);
            break;
        default:
            return;
    }
}

bool InputManager::HasClickHappend()
{
    if (IsClickDragging)
    {
        return false;
    }

    return Vector2Distance(InitialMousePosition, GetMousePosition()) < ClickDragDistance;
}
