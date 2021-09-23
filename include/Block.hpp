#pragma once

#include <raylib.h>
#include "Components.hpp"
#include "Entity.hpp"

class Block
{
public:
    Block(Entity* e, int x, int y, int w, int h, int layers);
    ~Block();
	
	static void collisionCallback(Entity* self, Entity* other);

};
