#pragma once

#include <string>
#include "Components.hpp"
#include "Entity.hpp"

class Paddle
{
public:
    Paddle(Entity* e, Vector2 pos, Vector2 size);
    ~Paddle();

    static void inputHandler(TransformComponent* t);
    static void collisionCallback(Entity* self, Entity* other);

private:
    Entity* m_entity{nullptr};
};
