#include "../include/Block.hpp"

Block::Block(Entity* e, int x, int y, int w, int h, int layers)
{
    e->addComponent<TransformComponent>(x, y, w, h);
    e->addComponent<LayerComponent>(layers);
    e->addComponent<DrawComponent>();
}

Block::~Block()
{
}

void Block::collisionCallback(Entity* self, Entity* other)
{
    auto tag = other->getComponent<CollisionComponent>()->getTag();
    if (tag == "ball") {
        self->getComponent<LayerComponent>()->layers -= 1;
		if (self->getComponent<LayerComponent>()->layers == 0)
			self->setState(Entity::State::Dead);
    }
}
