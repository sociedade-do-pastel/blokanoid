#pragma once

#include <raylib.h>
#include "Components.hpp"
#include "Entity.hpp"

class Block
{
public:
    Block(Entity* e, int x, int y, int w, int h, int layers);
    ~Block();

    void init();
private:
	Color getLayerColor(int layers);
	
	Entity* m_entity{nullptr};
};
