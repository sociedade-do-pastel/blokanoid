#include "../include/InputComponent.hpp"

InputComponent::InputComponent(std::function<void(TransformComponent*)> f)
    : m_inputFunction(f)
{
}

InputComponent::~InputComponent()
{
}

void InputComponent::init()
{
    m_owner->addComponent<TransformComponent>();
    m_transform = m_owner->getComponent<TransformComponent>();
}

void InputComponent::update()
{
    m_inputFunction(m_transform);
}
