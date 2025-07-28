#include <raylib.h>
#include "Game.h"

int main() {
	Game Game;
	Game.Start();

	while (!WindowShouldClose()) {
		Game.ProcessInput();
		Game.Update();
		Game.Render();
	}

	Game.End();

	return 0;
}