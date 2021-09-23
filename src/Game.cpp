#include "../include/Game.hpp"

std::vector<std::vector<int>> mapeiro = {
    {0, 1, 0, 2, 3, 4, 2, 2, 4, 0, 0, 0}, {0, 3, 3, 0, 0, 5, 4, 2, 2, 0, 0, 0},
    {0, 2, 3, 4, 5, 0, 2, 0, 2, 0, 0, 0}, {0, 4, 3, 0, 5, 0, 1, 3, 0, 0, 0, 0},
    {0, 2, 3, 4, 5, 0, 2, 0, 2, 0, 0, 0}, {0, 2, 3, 4, 5, 0, 2, 0, 2, 0, 0, 0}};

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

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(width, height, title);
    SetTargetFPS(targetFPS);

    BlockMap::mountMap(&m_manager, mapeiro, {20, 60},
                       {GetScreenWidth() - 40.0f, GetScreenHeight() - 200.0f});

    Wall::makeEntity(m_manager.addEntity(), {0, 50},
                     {5, (float)GetScreenHeight()});
    Wall::makeEntity(m_manager.addEntity(), {5, 50},
                     {GetScreenWidth() - 10.0f, 5});
    Wall::makeEntity(m_manager.addEntity(), {GetScreenWidth() - 5.0f, 50},
                     {5, (float)GetScreenHeight()});

    Paddle::makeEntity(m_manager.addEntity(),
                       {GetScreenWidth() / 2.0f, GetScreenHeight() - 25.0f},
                       {150.0f, 20.0f});

    Ball::makeEntity(m_manager.addEntity(), GetScreenWidth() / 2.0, 680, 10, 10,
                     ORANGE);

    return IsWindowReady();
}

void Game::runLoop()
{
    while (!WindowShouldClose()) {
        processInput();
        update();
        draw();
        m_manager.refresh();
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
    m_manager.update();
    m_manager.checkCollision();
}

void Game::draw()
{
    BeginDrawing();

    ClearBackground({30, 30, 30});
    m_manager.drawEntities();
	DrawText("Lifes: X X X", 10, 15, 25, WHITE);
	DrawText("Blocks remaining: 000", 320, 15, 25, WHITE);

    EndDrawing();
}
