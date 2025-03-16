#include <iostream>
#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

using namespace std;

int main() {

	Color Dark_Blue = Color{ 44, 44, 127, 255 };

	const int screenWidth = 300;
	const int screenHeight = 600;

	cout << "Hello World" << endl;

	InitWindow(screenWidth, screenHeight, "Cpp-Tetris-Game");
	SetTargetFPS(60);

	Grid grid = Grid();
	grid.Print();

	LBlock block = LBlock();

	while (WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(Dark_Blue);
		grid.Draw();
		block.Draw();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}