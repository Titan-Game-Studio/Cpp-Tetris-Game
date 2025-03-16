#include <iostream>
#include <raylib.h>
#include "grid.h"

using namespace std;

int main() {

	Color Dark_Blue = Color{ 44, 44, 127, 255 };

	const int screenWidth = 300;
	const int screenHeight = 600;

	cout << "Hello World" << endl;

	InitWindow(screenWidth, screenHeight, "Cpp-Tetris-Game");
	SetTargetFPS(60);

	Grid grid = Grid();
	grid.grid[0][0] = 1;
	grid.grid[3][5] = 3;
	grid.grid[7][7] = 5;
	grid.grid[17][8] = 7;
	grid.Print();

	while (WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(Dark_Blue);
		grid.Draw();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}