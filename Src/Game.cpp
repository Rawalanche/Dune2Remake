#include "Game.h"
#include <raylib.h>

Game::Game() {}

void Game::Start()
{
	const int ScreenWidth = 800;
	const int ScreenHeight = 600;

	InitWindow(800, 600, "Dune2 Remake");
	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
}

void Game::ProcessInput()
{
}

void Game::Update()
{
	if (WindowShouldClose())
	{
		IsRunning = false;
	}
}

void Game::Render()
{
	BeginDrawing();
	ClearBackground(DARKGRAY);
	EndDrawing();
}

void Game::End()
{
	CloseWindow();
}