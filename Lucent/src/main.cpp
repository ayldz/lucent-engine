#include <iostream>

#include "application/window.h"
#include "application/game.h"

int main()
{
	Game game{};

	game.Init();
	game.Run();


	return 0;
}