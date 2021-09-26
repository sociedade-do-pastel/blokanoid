#include "../include/Block.hpp"

int Block::qtBlock{0};

void Block::makeEntity(Entity* e, int x, int y, int w, int h, int layers)
{
    e->addComponent<TransformComponent>(x, y, w, h);
    e->addComponent<LayerComponent>(layers);
    e->addComponent<CollisionComponent>("block", collisionCallback);
    e->addComponent<DrawComponent>();
	++qtBlock;
}

void Block::collisionCallback(Entity* self, std::string tag, Rectangle colRec,
                              Rectangle otherRec)
{
    if (tag == "ball") {
        self->getComponent<LayerComponent>()->layers -= 1;
        if (self->getComponent<LayerComponent>()->layers == 0) {
            self->setState(Entity::State::Dead);
			--qtBlock;
		}
    }
}
