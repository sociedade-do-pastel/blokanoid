#include "../include/Manager.hpp"
#include <iostream>

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
    Entity* e = new Entity;
    std::unique_ptr<Entity> ptre{e};
    entities.emplace_back(std::move(ptre));
    return e;
}

void Manager::drawEntities()
{
    DrawComponent* d;
    for (auto& e : entities) {
        d = e->getComponent<DrawComponent>();
        if (d != nullptr)
            d->draw();
    }
}

void Manager::checkCollision()
{
    std::vector<Entity*> en;
    for (auto& e : entities) {
        if (e->getComponent<CollisionComponent>() != nullptr)
            en.push_back(e.get());
    }

    Rectangle rec1;
    Rectangle rec2;

    for (auto it1 = en.begin(); it1 != en.end(); ++it1) {
        for (auto it2 = it1 + 1; it2 != en.end(); ++it2) {
            rec1 = (*it1)->getComponent<TransformComponent>()->getRec();
            rec2 = (*it2)->getComponent<TransformComponent>()->getRec();

            if (CheckCollisionRecs(rec1, rec2)) {
                auto c1          = (*it1)->getComponent<CollisionComponent>();
                auto c2          = (*it2)->getComponent<CollisionComponent>();
                Rectangle colRec = GetCollisionRec(rec1, rec2);

                c1->executeCallback(c2->getTag(), colRec, rec2);
                c2->executeCallback(c1->getTag(), colRec, rec1);
            }
        }
    }
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
