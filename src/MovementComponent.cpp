#include "../include/MovementComponent.hpp"

MovementComponent::MovementComponent(Vector2 v) : direction(v)
{
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::init()
{
    m_owner->addComponent<TransformComponent>();
    m_transform = m_owner->getComponent<TransformComponent>();
}

void MovementComponent::update()
{
    m_transform->velocity = direction;
    m_transform->position.x += m_transform->velocity.x * m_transform->speed;
    m_transform->position.y += m_transform->velocity.y * m_transform->speed;
}
