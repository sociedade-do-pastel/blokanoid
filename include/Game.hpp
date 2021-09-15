#pragma once

#include <raylib.h>

class Game
{
public:
    Game(int width, int height);
    ~Game();

	bool initialize();
	void runLoop();
private:
	void processInput();
	void updateGame();
	void generateOutput();
private:
	int m_screenWidth;
	int m_screenHeight;
};
