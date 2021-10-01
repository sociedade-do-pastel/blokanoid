#pragma once

#include <raylib.h>
#include <string>

#include "Button.hpp"
#include "Components.hpp"
#include "Entity.hpp"
#include "Game.hpp"
#include "GameState.hpp"
#include "Manager.hpp"
#include "MenuState.hpp"

class GameOverState : public GameState
{
public:
    GameOverState(Manager* m, int dif, int qtVidas, int blckRemain);
    ~GameOverState();

    void init() override;
    void update() override;
    void loadState() override;
    void unloadState() override;
    void draw() override;

    GameState* getNextGameState() override;

private:
    int m_lifes;
    int m_difficulty;
    int m_blckRemain;

    std::vector<Entity*> m_entites{};
};
