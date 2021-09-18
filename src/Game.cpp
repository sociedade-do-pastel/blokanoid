#include "../include/Game.hpp"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char* title, int width, int height, bool isFullscreen,
                int targetFPS)
{
    if (isFullscreen) {
        width  = GetScreenWidth();
        height = GetScreenHeight();
        SetConfigFlags(FLAG_FULLSCREEN_MODE);
    }

    InitWindow(width, height, title);
    SetTargetFPS(targetFPS);

    return IsWindowReady();
}

void Game::runLoop()
{
    while (!WindowShouldClose()) {
        processInput();
        update();
        draw();
    }
}

void Game::shutdown()
{
    CloseWindow();
}

void Game::processInput()
{
}

void Game::update()
{
}

void Game::draw()
{
    BeginDrawing();
    EndDrawing();
}
