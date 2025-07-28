#pragma once

class Game
{
public:
	Game();
	void Start();
	void ProcessInput();
	void Update();
	void Render();
	void End();

private:
	bool IsRunning = true;
};