#include "../include/TransformComponent.hpp"

TransformComponent::TransformComponent(float x, float y, float w, float h,
                                       int scale)
    : position({x, y}), m_size({w, h}), scale(scale)
{
}

TransformComponent::~TransformComponent()
{
}

void TransformComponent::init()
{
}

void TransformComponent::update()
{
}

Rectangle TransformComponent::getRec() const
{
    return Rectangle{position.x, position.y, m_size.x * scale,
                     m_size.y * scale};
}
