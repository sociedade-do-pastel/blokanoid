#pragma once

#include <vector>
#include "BlockMap.hpp"
#include "Button.hpp"
#include "Components.hpp"
#include "GameState.hpp"
#include "PlayingState.hpp"

class MenuState : public GameState
{
public:
    MenuState(Manager* m);
    ~MenuState();

    void init() override;
    void update() override;
    void loadState() override;
    void unloadState() override;
    void draw() override;
    GameState* getNextGameState() override;

    int difficulty{0};
    bool buttonController[2];
    bool reconstructMap{true};

private:
    std::vector<Entity*> m_entites{};
	std::vector<std::vector<char>> m_mapRef{};
    std::vector<Entity*> m_map{};
};
