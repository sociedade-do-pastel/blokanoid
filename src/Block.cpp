#include "../include/Block.hpp"

Block::Block(Entity* e, int x, int y, int w, int h, int layers)
{
    e->addComponent<TransformComponent>(x, y, w, h);
    e->addComponent<ColorComponent>(getLayerColor(layers));
    e->addComponent<DrawComponent>();
}

Block::~Block()
{
}

void Block::init()
{
}

Color Block::getLayerColor(int layers)
{
    switch (layers) {
    case 1:
        return RED;
    case 2:
        return BLUE;
    case 3:
        return GREEN;
    case 4:
        return YELLOW;
    case 5:
        return PINK;
    default:
        return {0, 0, 0, 0};
    }
}
