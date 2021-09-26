#pragma once

#include <algorithm>
#include <memory>
#include <vector>
#include "AbstractComponent.hpp"
#include "Entity.hpp"

// forward declaration
class Entity;

class Manager
{
public:
    Manager();
    ~Manager();

    void update();
    void refresh();
    Entity* addEntity();
    void pause(bool state);

    std::vector<AbstractComponent*> drawnableComponents;
	std::vector<AbstractComponent*> collidableComponents;

private:
    std::vector<std::unique_ptr<Entity>> entities;
};
