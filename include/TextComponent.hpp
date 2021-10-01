#pragma once

#include <raylib.h>
#include <string>
#include "AbstractComponent.hpp"
#include "Manager.hpp"
#include "TransformComponent.hpp"

class TextComponent : public AbstractComponent
{
public:
    TextComponent(std::string content, Vector2 offset = {0, 0});
    ~TextComponent();

    void init() override;
    void update() override;

    void draw();

private:
    TransformComponent* m_transform{nullptr};
    std::string m_content;
    Vector2 m_offset;
};
