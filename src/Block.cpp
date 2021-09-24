#include "../include/Block.hpp"

void Block::makeEntity(Entity* e, int x, int y, int w, int h, int layers)
{
    e->addComponent<TransformComponent>(x, y, w, h);
    e->addComponent<LayerComponent>(layers);
    e->addComponent<CollisionComponent>("block", collisionCallback);
    e->addComponent<DrawComponent>();
}

void Block::collisionCallback(Entity* self, std::string tag, Rectangle colRec,
                              Rectangle otherRec)
{
    if (tag == "ball") {
        self->getComponent<LayerComponent>()->layers -= 1;
        if (self->getComponent<LayerComponent>()->layers == 0)
            self->setState(Entity::State::Dead);
    }
}
