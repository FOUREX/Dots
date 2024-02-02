#include <iostream>

#include "raylib.h"

#include "dots.h"
#include "properties.h"

int main()
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Yep!");
	SetTargetFPS(60);

	Dots dots(MAX_DOTS);

	dots.generateRandom();

	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_KP_ADD)) { speedMultiplier += 1.0f; }
		if (IsKeyDown(KEY_KP_SUBTRACT)) { speedMultiplier -= 1.0f; }

		BeginDrawing();

		ClearBackground(BLACK);		

		Vector2 mousePos = { (float)GetMouseX(), (float)GetMouseY()};
		dots.setTargetPos(mousePos);

		dots.update();
		dots.draw();

		DrawFPS(10, 10);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
