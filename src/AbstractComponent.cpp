#include "../include/AbstractComponent.hpp"

AbstractComponent::AbstractComponent()
{
}

AbstractComponent::~AbstractComponent()
{
}

template <typename T> T& AbstractComponent::getComponent() const
{
    return this;
}

Entity* AbstractComponent::getOwner() const
{
    return m_owner;
}

void AbstractComponent::setOwner(Entity* newOwner)
{
    m_owner = newOwner;
}
