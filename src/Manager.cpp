#include "../include/Manager.hpp"

Manager::Manager()
{
}

Manager::~Manager()
{
}

void Manager::update()
{
    for (auto& e : entities) {
        if (!(e->getState() == Entity::State::Paused))
            e->update();
    }
}

void Manager::refresh()
{
    auto eraseFunc = [](auto& e) {
        if (e->getState() == Entity::State::Dead)
            return true;
        return false;
    };

    entities.erase(std::remove_if(entities.begin(), entities.end(), eraseFunc),
                   entities.end());
}

Entity* Manager::addEntity()
{
    Entity* e = new Entity(this);
    std::unique_ptr<Entity> ptre{e};
    entities.emplace_back(std::move(ptre));
    return e;
}

void Manager::pause(bool state)
{
    if (state) {
        for (auto& e : entities)
            e->setState(Entity::State::Active);
    }
    else {
        for (auto& e : entities)
            e->setState(Entity::State::Paused);
    }
}

void Manager::clear()
{
    entities.erase(std::remove_if(entities.begin(), entities.end(),
                                  [](auto& e) { return true; }),
                   entities.end());
}
