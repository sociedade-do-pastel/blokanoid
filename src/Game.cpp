#include "../include/Game.hpp"

std::vector<std::vector<char>> mapeiro;

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

    m_lifes = 3;

    BlockMap::mountMap(&m_manager, mapeiro, {5, 55},
                       {GetScreenWidth() - 10.0f, GetScreenHeight() - 300.0f});

    m_leftWall = m_manager.addEntity();
    Wall::makeEntity(m_leftWall, {0, 50}, {5, (float)GetScreenHeight()});

    m_rightWall = m_manager.addEntity();
    Wall::makeEntity(m_rightWall, {GetScreenWidth() - 5.0f, 50},
                     {5, (float)GetScreenHeight()});

    Wall::makeEntity(m_manager.addEntity(), {5, 50},
                     {GetScreenWidth() - 10.0f, 5});

    m_paddle = m_manager.addEntity();
    Paddle::makeEntity(m_paddle,
                       {GetScreenWidth() / 2.0f, GetScreenHeight() - 25.0f},
                       {150.0f, 20.0f}, 4, ORANGE);

    m_ball = m_manager.addEntity();
    Ball::makeEntity(m_ball, GetScreenWidth() / 2.0, 680, 10, 10, 6, WHITE);

    return IsWindowReady();
}

void Game::runLoop()
{
    while (!WindowShouldClose() && !m_gameOver) {
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

void Game::processInput()
{
    if (IsKeyPressed(KEY_P)) {
        m_manager.pause(m_isPaused);
        m_isPaused = !m_isPaused;
    }
}

void Game::update()
{
    m_manager.update();

    auto colFunc = [](CollisionComponent* c1, CollisionComponent* c2) {
        auto rec1 = c1->getRec();
        auto rec2 = c2->getRec();

        if (CheckCollisionRecs(rec1, rec2)) {
            Rectangle colRec = GetCollisionRec(rec1, rec2);

            c1->executeCallback(c2->getTag(), colRec, rec2);
            c2->executeCallback(c1->getTag(), colRec, rec1);
        }
    };

    // check collision between ball and everything
    for (auto& c : m_manager.collidableComponents)
        colFunc(m_ball->getComponent<CollisionComponent>(),
                dynamic_cast<CollisionComponent*>(c));

    // check if the ball went out of screen
    if (m_ball->getComponent<CollisionComponent>()->getRec().y
        >= GetScreenHeight()) {
        m_ball->setState(Entity::State::Dead);
        m_ball = m_manager.addEntity();
        Ball::makeEntity(m_ball, GetScreenWidth() / 2.0, 680, 10, 10, 6, WHITE);
        --m_lifes;
    }

    // check collision between paddle and leftwall
    colFunc(m_paddle->getComponent<CollisionComponent>(),
            m_leftWall->getComponent<CollisionComponent>());

    // check collision between paddle and rightwall
    colFunc(m_paddle->getComponent<CollisionComponent>(),
            m_rightWall->getComponent<CollisionComponent>());

    // check if the player won
    if (Block::qtBlock <= 0)
        m_gameOver = true;

    // check if the player lost
    if (m_lifes <= 0)
        m_gameOver = true;
}

void Game::draw()
{
    std::string lifeText = "Lifes: ";
    for (int i{0}; i < m_lifes; ++i)
        lifeText += "X ";

    std::string blocksRemaining
        = "Blocks remaining: " + std::to_string(Block::qtBlock);

    BeginDrawing();

    ClearBackground({30, 30, 30});

    for (auto& c : m_manager.drawnableComponents)
        dynamic_cast<DrawComponent*>(c)->draw();

    DrawText(lifeText.c_str(), 10, 15, 25, WHITE);

    DrawText(blocksRemaining.c_str(),
             GetScreenWidth() - MeasureText(blocksRemaining.c_str(), 25) - 10,
             15, 25, WHITE);

    if (m_isPaused)
        DrawText("Game is paused",
                 GetScreenWidth() / 2 - MeasureText("Game is paused", 30) / 2,
                 GetScreenHeight() / 2, 30, WHITE);

    EndDrawing();
}
