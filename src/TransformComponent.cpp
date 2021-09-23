#include "../include/TransformComponent.hpp"

TransformComponent::TransformComponent(float x, float y, float w, float h,
                                       int scale)
    : position({x, y}), size({w, h}), scale(scale)
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
