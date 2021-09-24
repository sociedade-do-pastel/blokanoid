#pragma once

#include "Components.hpp"
#include "Entity.hpp"

class Wall
{
public:
    static void makeEntity(Entity* e, Vector2 pos, Vector2 size);
    static void collisionCallback(Entity* self, std::string tag,
                                  Rectangle colRec, Rectangle otherRec);
};
