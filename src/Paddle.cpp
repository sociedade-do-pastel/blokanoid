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
