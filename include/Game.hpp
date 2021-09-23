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

    Manager m_manager{};
};
