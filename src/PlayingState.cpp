#include "../include/PlayingState.hpp"

PlayingState::PlayingState(Manager* m, int dif,
                           std::vector<std::vector<char>> map)
    : m_difficulty(dif), m_blockMap(map)
{
    m_manager = m;
    m_name    = "playing";
}

PlayingState::~PlayingState()
{
}

void PlayingState::init()
{
}

void PlayingState::update()
{
    if (IsKeyPressed(KEY_P)) {
        m_manager->pause(m_isPaused);
        m_isPaused = !m_isPaused;
    }

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
    for (auto& c : m_manager->collidableComponents)
        colFunc(m_ball->getComponent<CollisionComponent>(),
                dynamic_cast<CollisionComponent*>(c));

    // check if the ball went out of screen
    if (m_ball->getComponent<CollisionComponent>()->getRec().y
        >= GetScreenHeight()) {

        m_ball->setState(Entity::State::Dead);

        m_ball = m_manager->addEntity();
        Ball::makeEntity(m_ball, GetScreenWidth() / 2.0, 680, 10, 10,
                         6 + 1 * m_difficulty, WHITE);
        m_ball->addComponent<PositionSyncComponent>(
            m_paddle->getComponent<TransformComponent>(), Ball::unsyncFunc);

        Ball::ballRunning = false;
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

void PlayingState::loadState()
{
    m_lifes = 3;

    BlockMap::mountMap(m_manager, m_blockMap, {5, 55},
                       {GetScreenWidth() - 10.0f, GetScreenHeight() - 300.0f});

    m_leftWall = m_manager->addEntity();
    Wall::makeEntity(m_leftWall, {0, 50}, {5, (float)GetScreenHeight()});

    m_rightWall = m_manager->addEntity();
    Wall::makeEntity(m_rightWall, {GetScreenWidth() - 5.0f, 50},
                     {5, (float)GetScreenHeight()});

    Wall::makeEntity(m_manager->addEntity(), {5, 50},
                     {GetScreenWidth() - 10.0f, 5});

    m_paddle = m_manager->addEntity();
    Paddle::makeEntity(m_paddle,
                       {GetScreenWidth() / 2.0f, GetScreenHeight() - 25.0f},
                       {150.0f - 50 * m_difficulty, 20.0f}, 4, ORANGE);

    m_ball = m_manager->addEntity();
    Ball::makeEntity(m_ball, GetScreenWidth() / 2.0, 680, 10, 10,
                     6 + 1 * m_difficulty, WHITE);

    m_ball->addComponent<PositionSyncComponent>(
        m_paddle->getComponent<TransformComponent>(), Ball::unsyncFunc);
}

void PlayingState::unloadState()
{
}

void PlayingState::draw()
{
    std::string lifeText = "Lifes: ";
    for (int i{0}; i < m_lifes; ++i)
        lifeText += "X ";

    std::string blocksRemaining
        = "Blocks remaining: " + std::to_string(Block::qtBlock);

    DrawText(lifeText.c_str(), 10, 15, 25, WHITE);

    DrawText(blocksRemaining.c_str(),
             GetScreenWidth() - MeasureText(blocksRemaining.c_str(), 25) - 10,
             15, 25, WHITE);

    if (m_isPaused) {
        DrawText("Game is paused",
                 GetScreenWidth() / 2 - MeasureText("Game is paused", 30) / 2,
                 GetScreenHeight() / 2, 30, WHITE);
    }
    else if (!Ball::ballRunning) {
        DrawText("Press space to launch",
                 GetScreenWidth() / 2
                     - MeasureText("Press space to launch", 30) / 2,
                 GetScreenHeight() / 2, 30, WHITE);
    }
}

GameState* PlayingState::getNextGameState()
{
    return this;
}
