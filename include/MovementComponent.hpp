#pragma once

#include "AbstractComponent.hpp"
#include "TransformComponent.hpp"

class MovementComponent : public AbstractComponent
{
public:
    MovementComponent(Vector2 d = {0, 0}, float speed=3);
    ~MovementComponent();

    void init() override;
    void update() override;

    Vector2 direction;

private:
    TransformComponent* m_transform{nullptr};
    float speed;
};
