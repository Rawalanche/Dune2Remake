#pragma once
#include "InputManager.h"
#include "Map.h"
#include "Types.h"
#include "Viewport.h"

class Map;
class InputManager;

class Game
{
public:
	static Game* GetInstance() { return Instance; }

	const Size2D ScreenSize = Size2D(1920, 1080);

	Viewport Viewport;


	Game() {};
	void Initialize();
	void Update();
	void Render();
	void Destroy();

private:
	static Game* Instance;

	bool IsRunning = true;
	InputManager InputManager;
	Map Map;
};