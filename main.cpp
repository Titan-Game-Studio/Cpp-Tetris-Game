#include <iostream>
#include <raylib.h>
#include "game.h"

using namespace std;

int main() {

	Color Dark_Blue = Color{ 44, 44, 127, 255 };
	const int screenWidth = 300;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Cpp-Tetris-Game");
	SetTargetFPS(60);

	Game game = Game();

	while (WindowShouldClose() == false) 
	{
		game.HandleInput();
		BeginDrawing();
		ClearBackground(Dark_Blue);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}