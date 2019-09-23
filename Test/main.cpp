#include "Game.h"
#include <Windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
{
	std::unique_ptr<Game> newGame(new Game);

	newGame->Set_DEBUG_MODE(false);

	newGame->SetWindowDimension(800, 600);
	newGame->SetWindowName("FireLight engine v0.0.1 alpha");
	newGame->Start();
	return 0;
}