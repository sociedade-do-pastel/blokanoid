#include "../include/Wall.hpp"

void Wall::makeEntity(Entity* e, Vector2 pos, Vector2 size)
{
    e->addComponent<TransformComponent>(pos.x, pos.y, size.x, size.y);
    e->addComponent<CollisionComponent>("wall", collisionCallback);
    e->addComponent<ColorComponent>(PURPLE);
    e->addComponent<DrawComponent>();
}

void Wall::collisionCallback(Entity* self, Entity* other)
{
    return;
}
