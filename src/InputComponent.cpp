#include "../include/InputComponent.hpp"

InputComponent::InputComponent()
{
}

InputComponent::~InputComponent()
{
}

void InputComponent::init()
{
	m_owner->addComponent<TransformComponent>();	
	transform = m_owner->getComponent<TransformComponent>();
}

void InputComponent::update()
{
    if (IsKeyDown(KEY_A))
        transform->velocity.x = -1;
    else if (IsKeyDown(KEY_D))
        transform->velocity.x = 1;
    else
        transform->velocity.x = 0;

	if (IsKeyDown(KEY_W))
        transform->velocity.y = -1;
    else if (IsKeyDown(KEY_S))
        transform->velocity.y = 1;
    else
        transform->velocity.y = 0;
}
