#pragma once

#include "Components.hpp"
#include "Entity.hpp"

class Wall
{
public:
    Wall(Entity* e, Vector2 pos, Vector2 size);
    ~Wall();

    static void collisionCallback(Entity* self, Entity* other);
	
private:
    Entity* m_entity{nullptr};
    Vector2 m_pos;
    Vector2 m_size;
};
