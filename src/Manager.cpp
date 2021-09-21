#include "../include/Manager.hpp"

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

Entity& Manager::addEntity()
{
    Entity* e = new Entity;
    std::unique_ptr<Entity> ptre{e};
    entities.emplace_back(std::move(ptre));
    return *e;
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
