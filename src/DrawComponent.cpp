#include "../include/DrawComponent.hpp"

DrawComponent::DrawComponent()
{
}

DrawComponent::~DrawComponent()
{
}

void DrawComponent::init()
{
    m_owner->addComponent<TransformComponent>();
    m_owner->addComponent<ColorComponent>(RED);

    m_transform = m_owner->getComponent<TransformComponent>();
    m_color     = m_owner->getComponent<ColorComponent>();
}

void DrawComponent::update()
{
}

void DrawComponent::draw()
{
    Vector2 size = {m_transform->size.x * m_transform->scale,
                    m_transform->size.y * m_transform->scale};
    DrawRectangleV(m_transform->position, size, m_color->color);
}
