#pragma once

#include <memory>
#include <raylib.h>

#include "Components.hpp"
#include "Entity.hpp"
#include "GameState.hpp"
#include "Manager.hpp"
#include "MenuState.hpp"

class Game
{
public:
    Game();
    ~Game();

    bool init(const char* title, int width, int height, int targetFPS);
    void runLoop();
    void shutdown();
    void changeState();

    static bool isGameOver;

private:
    void processInput();
    void update();
    void draw();

    Manager m_manager{};
    std::unique_ptr<GameState> m_currentState;
};
