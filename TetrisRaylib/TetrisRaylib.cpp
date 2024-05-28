
#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <string>

double lastUpdateTime = 0;

std::string FormatWithZeros(int number, int width)
{
	std::string numberText = std::to_string(number);
	int leadingZeros = width - numberText.length();
	return numberText = std::string(leadingZeros, '0') + numberText;
}

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

int main()
{
	InitWindow(500, 620, "Tetris");
	SetTargetFPS(60);

	Font font = LoadFontEx("Font/IMMORTAL.ttf", 64, 0, 0);

	Game game = Game();

	while (WindowShouldClose() == false)
	{
		game.HandleInput();

		if (EventTriggered(0.2))
		{
			game.MoveBlockDown();
		}

		BeginDrawing();
		ClearBackground(darkBlue);

		DrawTextEx(font, "Score", { 365, 15 }, 38, 2, WHITE);
		DrawTextEx(font, "Next", { 370, 170 }, 38, 2, WHITE);

		if (game.gameOver)
		{
			DrawTextEx(font, "GAME\n\n\nOVER", {354, 450}, 38, 2, WHITE);
		}
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue);

		std::string scoreText = FormatWithZeros(game.score, 5);
		DrawTextEx(font, scoreText.c_str(), { 353, 65 }, 38, 2, WHITE);

		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);
		game.Draw();

		EndDrawing();
	}

	CloseWindow();

}
