#pragma once

#include <raylib.h>
#include "AbstractComponent.hpp"

class TransformComponent : public AbstractComponent
{
public:
    TransformComponent(float x = 0, float y = 0, float w = 0, float h = 0,
                       int scale = 1);
    ~TransformComponent();

    void init() override;
    void update() override;

	Rectangle getRec() const;

    Vector2 position;
    int scale;

private:
	Vector2 m_size;
};
