#include "../include/Paddle.hpp"

void Paddle::makeEntity(Entity* e, Vector2 pos, Vector2 size, float speed,
                        Color color)
{
    e->addComponent<TransformComponent>(pos.x, pos.y, size.x, size.y);
    e->addComponent<MovementComponent>(Vector2{0, 0}, speed);
    e->addComponent<InputComponent>(inputHandler);
    e->addComponent<CollisionComponent>("paddle", collisionCallback);
    e->addComponent<ColorComponent>(color);
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

void Paddle::collisionCallback(Entity* self, std::string tag, Rectangle colRec,
                               Rectangle otherRec)
{
    auto m = self->getComponent<TransformComponent>();

    if (tag == "wall") {
        if (m->position.x >= colRec.x)
            m->position.x += colRec.width;
        else
            m->position.x -= colRec.width;
    }
}
