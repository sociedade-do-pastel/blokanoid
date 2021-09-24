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
    Vector2 size;
    Vector2 velocity{0, 0};
    int scale;
    int speed{4};

private:
};
