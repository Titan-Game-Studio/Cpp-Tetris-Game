#include <iostream>
#include <raylib.h>
#include "game.h"

using namespace std;

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main() {

	Color Dark_Blue = Color{ 44, 44, 127, 255 };
	const int screenWidth = 300;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Cpp-Tetris-Game");
	SetTargetFPS(60);

	Game game = Game();

	while (WindowShouldClose() == false)
	{
		if (EventTriggered(0.2))
		{
			game.MoveBlockDown();
		}

		game.HandleInput();
		BeginDrawing();
		ClearBackground(Dark_Blue);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}