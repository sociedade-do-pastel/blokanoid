#include "Game.hpp"

Game::Game(int width, int height) : m_screenWidth(width), m_screenHeight(height)
{
}

Game::~Game()
{
}

bool Game::initialize()
{
	InitWindow(m_screenWidth, m_screenHeight, "Blokanoid");
    return true;
}

void Game::runLoop()
{
	while (!WindowShouldClose()) {
		processInput();
		updateGame();
		generateOutput();
	}
}

void Game::processInput()
{
}

void Game::updateGame()
{
}

void Game::generateOutput()
{
	BeginDrawing();
	EndDrawing();
}
