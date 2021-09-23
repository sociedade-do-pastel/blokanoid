#include "../include/InputComponent.hpp"

InputComponent::InputComponent(std::function<void(Entity*)> f)
    : m_inputFunction(f)
{
}

InputComponent::~InputComponent()
{
}

void InputComponent::init()
{
}

void InputComponent::update()
{
    m_inputFunction(m_owner);
}
