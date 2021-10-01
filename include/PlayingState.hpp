#pragma once

#include <raylib.h>
#include <vector>

#include "Ball.hpp"
#include "BlockMap.hpp"
#include "Components.hpp"
#include "Entity.hpp"
#include "GameState.hpp"
#include "Manager.hpp"
#include "Paddle.hpp"
#include "Wall.hpp"

class PlayingState : public GameState
{
public:
    PlayingState(Manager* m, int dif, std::vector<std::vector<char>> map);
    ~PlayingState();

    void init() override;
    void update() override;
    void loadState() override;
    void unloadState() override;
    void draw() override;

    GameState* getNextGameState() override;

private:
    Entity* m_paddle{nullptr};
    Entity* m_ball{nullptr};
    Entity* m_leftWall{nullptr};
    Entity* m_rightWall{nullptr};

    bool m_gameOver{false};
    bool m_isPaused{false};
    int m_lifes{0};
    int m_difficulty;
    std::vector<std::vector<char>> m_blockMap;
};
