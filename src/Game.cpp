#include "../include/Game.hpp"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char* title, int width, int height, int targetFPS)
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(width, height, title);
    SetTargetFPS(targetFPS);

    m_currentState = std::make_unique<MenuState>(&m_manager);
    m_currentState->loadState();

    return IsWindowReady();
}

void Game::runLoop()
{
    while (!WindowShouldClose()) {
        m_manager.refresh();
        processInput();
        update();
        draw();
    }
}

void Game::shutdown()
{
    CloseWindow();
}

void Game::changeState()
{
    m_manager.clear();
    m_currentState.reset(std::move(m_currentState->getNextGameState()));
    m_currentState->loadState();
}

void Game::processInput()
{
}

void Game::update()
{
    m_manager.update();
    m_currentState->update();

    if (GameState::stateChanged) {
        changeState();
        GameState::stateChanged = false;
    }
}

void Game::draw()
{
    BeginDrawing();

    ClearBackground({30, 30, 30});

    for (auto& c : m_manager.drawnableComponents)
        dynamic_cast<DrawComponent*>(c)->draw();
    m_currentState->draw();

    EndDrawing();
}
