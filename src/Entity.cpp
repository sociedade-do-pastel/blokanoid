#include "../include/Entity.hpp"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::init()
{
    setState(State::Active);
}

void Entity::update()
{
    for (auto& c : m_components)
        c->update();
}

void Entity::removeComponent(AbstractComponent* comp)
{
    // m_components.erase(std::remove_if(m_components.begin(), m_components.end(),
    //                                   [comp](auto c) { return c == comp; }));
}

Entity::State Entity::getState() const
{
    return m_state;
}

void Entity::setState(State s)
{
	m_state = s;
}
