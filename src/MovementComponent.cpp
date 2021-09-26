#include "../include/MovementComponent.hpp"

MovementComponent::MovementComponent(Vector2 v, float speed)
    : direction(v), speed(speed)
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
    m_transform->position.x += direction.x * speed;
    m_transform->position.y += direction.y * speed;
}
