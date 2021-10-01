#include "../include/GameOverState.hpp"

GameOverState::GameOverState(Manager* m, int dif, int qtLifes, int blckRemain)
    : m_lifes(qtLifes), m_difficulty(dif), m_blckRemain(blckRemain)
{
    m_manager = m;
}

GameOverState::~GameOverState()
{
}

void GameOverState::init()
{
}

void GameOverState::update()
{
}

void GameOverState::loadState()
{
    // Menu button
    auto e = m_manager->addEntity();
    Button::makeEntity(e, 20, GetScreenHeight() - 122, GetScreenWidth() - 40,
                       50, 20.0f, 10.f, RED, GREEN, "Menu",
                       [](Entity* e) { GameState::stateChanged = true; });
    e->getComponent<ColorComponent>()->color = Color{118, 0, 0, 255};
    m_entites.push_back(e);

    // Exit button
    e = m_manager->addEntity();
    Button::makeEntity(e, 20, GetScreenHeight() - 70, GetScreenWidth() - 40, 50,
                       20.0f, 10.f, RED, GREEN, "Exit",
                       [](Entity* e) { Game::isGameOver = true; });
    e->getComponent<ColorComponent>()->color = Color{118, 0, 0, 255};
    m_entites.push_back(e);
}

void GameOverState::unloadState()
{
}

void GameOverState::draw()
{
    auto getXToCenter = [](const char* content, int fontSize) {
        return GetScreenWidth() / 2 - MeasureText(content, fontSize) / 2;
    };

    DrawText("Game Over", getXToCenter("Game Over", 75), 20, 75, WHITE);

    if (m_lifes == 0) {
        DrawRectangleV({20.0f, 100.0f}, {GetScreenWidth() - 40.0f, 50.0f}, RED);
        DrawText("You lost", getXToCenter("You lost", 36), 110, 36, WHITE);
    }
    else {
        DrawRectangleV({20.0f, 100.0f}, {GetScreenWidth() - 40.0f, 50.0f},
                       GREEN);
        DrawText("You won", getXToCenter("You won", 36), 110, 36, WHITE);
    }

    std::string difT = "Difficulty:                    ";
    difT += m_difficulty == 0 ? "Normal" : "  Hard";

    std::string lifT = "Lifes remaining:              ";
    for (int i{0}; i < 3; ++i) {
        if (i < m_lifes)
            lifT += " x";
        else
            lifT += " -";
    }

    std::string blkT = "Blocks remaining:               ";
    if (m_blckRemain < 10)
        blkT += "  " + std::to_string(m_blckRemain);
    else if (m_blckRemain < 100)
        blkT += " " + std::to_string(m_blckRemain);
    else
        blkT += std::to_string(m_blckRemain);

    DrawText("Summary", getXToCenter("Summary", 45), 240, 45, WHITE);
    DrawText(difT.c_str(), 20, 300, 36, WHITE);
    DrawText(lifT.c_str(), 20, 340, 36, WHITE);
    DrawText(blkT.c_str(), 20, 380, 36, WHITE);

    for (auto& e : m_entites)
        e->getComponent<TextComponent>()->draw();
}

GameState* GameOverState::getNextGameState()
{
    GameState* e = new MenuState(m_manager);
    return e;
}
