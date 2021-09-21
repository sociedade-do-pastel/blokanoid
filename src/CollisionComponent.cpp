#include "../include/CollisionComponent.hpp"

CollisionComponent::CollisionComponent(
    std::string tag, std::function<void(Entity*, Entity*)> f)
    : m_tag(tag), m_callbackFunction(f)
{
}

CollisionComponent::~CollisionComponent()
{
}

void CollisionComponent::init()
{
}

void CollisionComponent::update()
{
}

std::string CollisionComponent::getTag() const
{
    return m_tag;
}

void CollisionComponent::executeCallback(Entity* other)
{
    m_callbackFunction(m_owner, other);
}
