#include "../include/DrawComponent.hpp"

DrawComponent::DrawComponent()
{
}

DrawComponent::~DrawComponent()
{
    auto& v = m_owner->getManager()->drawnableComponents;

    v.erase(std::remove_if(v.begin(), v.end(),
                           [this](auto e) { return e == this; }),
            v.end());
}

void DrawComponent::init()
{
    m_owner->addComponent<TransformComponent>();
    m_owner->addComponent<ColorComponent>(RED);

    m_transform = m_owner->getComponent<TransformComponent>();
    m_color     = m_owner->getComponent<ColorComponent>();

    m_owner->getManager()->drawnableComponents.push_back(this);
}

void DrawComponent::update()
{
}

void DrawComponent::draw()
{
	Rectangle rec = m_transform->getRec();
	DrawRectangleRec(rec, m_color->color);
}
