#include "../include/MenuState.hpp"

MenuState::MenuState(Manager* m)
{
    m_manager = m;
    m_name    = "menu";
}

MenuState::~MenuState()
{
}

void MenuState::init()
{
}

void MenuState::update()
{
    if (reconstructMap) {
        for (auto& m : m_map)
            m->setState(Entity::State::Dead);

        m_map.clear();
        m_map          = BlockMap::mountMap(m_manager, {20, 300},
                                   {GetScreenWidth() - 40.0f, 450.0f});
        reconstructMap = false;
    }
}

void MenuState::loadState()
{
    buttonController[0] = true;
    buttonController[1] = false;

    // Normal button
    auto e = m_manager->addEntity();
    Button::makeEntity(
        e, 20, 65, GetScreenWidth() / 2 - 21, 50, 20.0f, 10.f, RED, GREEN,
        "Normal",
        [this](Entity* e) {
            buttonController[0]                      = true;
            buttonController[1]                      = false;
            e->getComponent<ColorComponent>()->color = Color{118, 0, 0, 255};
            difficulty                               = 0;
        },
        &buttonController[0]);
    e->getComponent<ColorComponent>()->color = Color{118, 0, 0, 255};
    m_entites.push_back(e);

    // Hard button
    e = m_manager->addEntity();
    Button::makeEntity(
        e, GetScreenWidth() / 2 + 2, 65, GetScreenWidth() / 2 - 21, 50, 20.0f,
        10.f, RED, GREEN, "Hard",
        [this](Entity* e) {
            buttonController[1]                      = true;
            buttonController[0]                      = false;
            e->getComponent<ColorComponent>()->color = Color{118, 0, 0, 255};
            difficulty                               = 1;
        },
        &buttonController[1]);
    m_entites.push_back(e);

    // Reroll button
    e = m_manager->addEntity();
    Button::makeEntity(e, GetScreenWidth() - 160, 180, 140, 40, 20.0f, 5.f, RED,
                       GREEN, "Reroll",
                       [this](Entity* e) { reconstructMap = true; });
    m_entites.push_back(e);

    // Start button
    e = m_manager->addEntity();
    Button::makeEntity(e, 20, GetScreenHeight() - 70, GetScreenWidth() - 40, 50,
                       GetScreenWidth() / 2 - 70, 10.f, RED, GREEN, "Start",
                       [](Entity* e) {
						   GameState::stateChanged = true;
					   });
    m_entites.push_back(e);
}

void MenuState::unloadState()
{
}

void MenuState::draw()
{
    DrawText("Difficulty", 20, 20, 36, WHITE);
    DrawText("Map", 20, 180, 36, WHITE);

    for (auto& e : m_entites)
        e->getComponent<TextComponent>()->draw();
}

GameState* MenuState::getNextGameState()
{
	GameState* e = new PlayingState(m_manager);
	return e;
}
