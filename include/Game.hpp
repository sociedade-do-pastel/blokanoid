#pragma once

#include <raylib.h>

#include "../include/Ball.hpp"
#include "../include/BlockMap.hpp"
#include "../include/Components.hpp"
#include "../include/Entity.hpp"
#include "../include/Manager.hpp"
#include "../include/Paddle.hpp"
#include "../include/Wall.hpp"

class Game
{
public:
    Game();
    ~Game();

    bool init(const char* title, int width, int height, bool isFullscreen,
              int targetFPS);
    void runLoop();
    void shutdown();

private:
    void processInput();
    void update();
    void draw();

    Entity* m_paddle{nullptr};
    Entity* m_ball{nullptr};
    Entity* m_leftWall{nullptr};
    Entity* m_rightWall{nullptr};

    Manager m_manager{};
    bool m_isPaused{false};
	bool m_gameOver{false};
	int m_lifes{0};
};
