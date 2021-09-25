#pragma once

#include <algorithm>
#include <memory>
#include <vector>
#include "Components.hpp"
#include "Entity.hpp"

class Manager
{
public:
    Manager();
    ~Manager();

    void update();
    void refresh();
    Entity* addEntity();
    void drawEntities();
    void checkCollision();
	void pause(bool state);

private:
    std::vector<std::unique_ptr<Entity>> entities;
};
