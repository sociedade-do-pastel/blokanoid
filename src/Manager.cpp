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
    for (auto& e : entities)
        e->update();
}

void Manager::refresh()
{
    entities.erase(std::remove_if(entities.begin(), entities.end(),
                                  [](auto& e) {
                                      if (e->getState() == Entity::State::Dead)
                                          return true;
                                      return false;
                                  }),
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
            rec1 = {(*it1)->getComponent<TransformComponent>()->position.x,
                    (*it1)->getComponent<TransformComponent>()->position.y,
                    (*it1)->getComponent<TransformComponent>()->size.x,
                    (*it1)->getComponent<TransformComponent>()->size.y};

            rec2 = {(*it2)->getComponent<TransformComponent>()->position.x,
                    (*it2)->getComponent<TransformComponent>()->position.y,
                    (*it2)->getComponent<TransformComponent>()->size.x,
                    (*it2)->getComponent<TransformComponent>()->size.y};

            if (CheckCollisionRecs(rec1, rec2)) {				
				(*it1)->getComponent<CollisionComponent>()->executeCallback(*it2);
				(*it2)->getComponent<CollisionComponent>()->executeCallback(*it1);
            }
        }
    }
}
