#pragma once

#include <memory>
#include <vector>
#include "Entity.hpp"
#include "Components.hpp"

class Manager
{
public:
    Manager();
    ~Manager();

    void update();
    void refresh();
    Entity* addEntity();
    void drawEntities();

private:
    std::vector<std::unique_ptr<Entity>> entities;
};
