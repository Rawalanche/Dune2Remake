#include <raylib.h>
#include "Game.h"

int main() {
	Game Game;
	Game.Initialize();

	while (!WindowShouldClose()) {
		Game.Update();
	}

	Game.Destroy();

	return 0;
}