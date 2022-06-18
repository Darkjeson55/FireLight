#include "FireLight.h"

int main()
{
	InitWindow(800, 600, "Hello");

	while (!WindowShouldClose())
	{
		UpdateWindow();
	}

	CloseWindow();

	return 0;
}