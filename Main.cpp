#include "include/Game.hpp"

int main(int argc, char *argv[])
{
    Game game(1280, 720);
	
	if (bool success = game.initialize(); success)
		game.runLoop();
	
    return 0;
}
