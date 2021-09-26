#pragma once

#include <string>
#include "Components.hpp"
#include "Entity.hpp"

class Paddle
{
public:
    static void makeEntity(Entity* e, Vector2 pos, Vector2 size, float speed,
                           Color color);
    static void inputHandler(Entity* t);
    static void collisionCallback(Entity* self, std::string tag,
                                  Rectangle colRec, Rectangle otherRec);
};
