#include <iostream>

#include "application/window.h"
#include "application/game.h"

Game& game = Game::Instance();

int main()
{
	game.Init();
	game.Run();


	return 0;
}