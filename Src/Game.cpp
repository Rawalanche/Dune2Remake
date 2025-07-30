#include "Game.h"
#include <raylib.h>
#include <raymath.h>

// Define the static member
Game* Game::Instance = nullptr;

void Game::Initialize()
{
	Instance = this;

	InitWindow(ScreenSize.Width, ScreenSize.Height, "Dune2 Remake");
	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

	Map.Initialize(Size2D(64, 64));
	Viewport.Initialize();
	InputManager.Initialize();
}

void Game::Update()
{
	if (WindowShouldClose()) { IsRunning = false; }

	InputManager.ProcessInput();
	Viewport.Update();

	Render();
}

void Game::Render()
{
	BeginDrawing();
	BeginMode2D(Viewport.GetCamera());
	ClearBackground(BLACK);
	Map.Render();
	EndMode2D();
	EndDrawing();
}

void Game::Destroy()
{
	CloseWindow();
}