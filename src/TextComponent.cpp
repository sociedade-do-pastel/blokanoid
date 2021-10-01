#include "../include/TextComponent.hpp"

TextComponent::TextComponent(std::string content, Vector2 offset)
    : m_content(content), m_offset(offset)
{
}

TextComponent::~TextComponent()
{
}

void TextComponent::init()
{
    m_owner->addComponent<TransformComponent>();
    m_transform = m_owner->getComponent<TransformComponent>();
}

void TextComponent::update()
{
}

void TextComponent::draw()
{
    Rectangle rec = m_transform->getRec();
    DrawText(m_content.c_str(), rec.x + m_offset.x, rec.y + m_offset.y, 36,
             WHITE);
}
