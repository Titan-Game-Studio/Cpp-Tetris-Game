#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

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

	const int screenWidth = 500;
	const int screenHeight = 620;
	const int targetFPS = 60;
	const double deltaTime = 0.2;

	InitWindow(screenWidth, screenHeight, "Tetris-Game");
	SetTargetFPS(targetFPS);

	Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

	Game game = Game();

	while (WindowShouldClose() == false)
	{
		if (EventTriggered(deltaTime))
		{
			game.MoveBlockDown();
		}

		game.HandleInput();
		BeginDrawing();
		ClearBackground(darkBlue);
		DrawTextEx(font, "Score", { 365, 15 }, 38, 2, WHITE);
		DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
		if (game.gameOver)
		{
			DrawTextEx(font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
		}
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue);

		char scoreText[10];
		snprintf(scoreText, sizeof(scoreText), "%d", game.score);
		Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

		DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, WHITE);
		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}