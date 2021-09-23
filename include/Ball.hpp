#pragma once

#include <raylib.h>
#include "Components.hpp"
#include "Entity.hpp"

class Ball
{
public:
    static void makeEntity(Entity*, int x, int y, int w, int h, Color color);
    static void collisionCallback(Entity* self, Entity* other);
};
