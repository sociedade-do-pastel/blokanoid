#include "../include/Game.hpp"

int main(int argc, char *argv[])
{
    Game game;
	bool success = game.init("Blokanoid", 600, 800, 60);
	
	if (success)
		game.runLoop();

	game.shutdown();
    return 0;
}
