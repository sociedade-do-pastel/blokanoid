#pragma once

#include <raylib.h>
#include "Components.hpp"
#include "Entity.hpp"

class Block
{
public:
    static void makeEntity(Entity* e, int x, int y, int w, int h, int layers);
    static void collisionCallback(Entity* self, Entity* other);
};
