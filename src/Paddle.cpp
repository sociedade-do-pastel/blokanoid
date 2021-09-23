#include "../include/Paddle.hpp"

void Paddle::makeEntity(Entity* e, Vector2 pos, Vector2 size)
{
    e->addComponent<TransformComponent>(pos.x, pos.y, size.x, size.y);
    e->addComponent<MovementComponent>();
    e->addComponent<InputComponent>(inputHandler);
    e->addComponent<CollisionComponent>("paddle", collisionCallback);
    e->addComponent<ColorComponent>(Color{0, 0, 255, 100});
    e->addComponent<DrawComponent>();
}

void Paddle::inputHandler(Entity* self)
{
    MovementComponent* m = self->getComponent<MovementComponent>();
    if (IsKeyDown(KEY_A))
        m->direction.x = -1;
    else if (IsKeyDown(KEY_D))
        m->direction.x = 1;
    else
        m->direction.x = 0;
}

void Paddle::collisionCallback(Entity* self, Entity* other)
{
    auto tag = other->getComponent<CollisionComponent>()->getTag();
    if (tag == "wall") {
        auto m = self->getComponent<TransformComponent>();
        auto n = other->getComponent<TransformComponent>();

        if (m->position.x > n->position.x)
            m->position.x = n->position.x + n->size.x;
        else
            m->position.x = n->position.x - m->size.x;
    }
}
