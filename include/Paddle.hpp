#pragma once

#include <string>
#include "Components.hpp"
#include "Entity.hpp"

class Paddle
{
public:
    static void makeEntity(Entity* e, Vector2 pos, Vector2 size);
    static void inputHandler(Entity* t);
    static void collisionCallback(Entity* self, Entity* other);
};
