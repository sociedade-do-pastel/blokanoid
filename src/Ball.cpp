#include "../include/Ball.hpp"

void Ball::makeEntity(Entity* e, int x, int y, int w, int h, Color color)
{
    e->addComponent<TransformComponent>(x, y, w, h);
    e->addComponent<MovementComponent>(Vector2{1, -1});
    e->addComponent<CollisionComponent>("ball", collisionCallback);
    e->addComponent<ColorComponent>(color);
    e->addComponent<DrawComponent>();
}

void Ball::collisionCallback(Entity* self, Entity* other)
{

    auto tag = other->getComponent<CollisionComponent>()->getTag();
    auto m   = self->getComponent<TransformComponent>();
    auto n   = other->getComponent<TransformComponent>();

    Rectangle rec1 = {self->getComponent<TransformComponent>()->position.x,
                      self->getComponent<TransformComponent>()->position.y,
                      self->getComponent<TransformComponent>()->size.x,
                      self->getComponent<TransformComponent>()->size.y};

    Rectangle rec2 = {other->getComponent<TransformComponent>()->position.x,
                      other->getComponent<TransformComponent>()->position.y,
                      other->getComponent<TransformComponent>()->size.x,
                      other->getComponent<TransformComponent>()->size.y};

    auto colRec = GetCollisionRec(rec1, rec2);

    if (tag == "block" || tag == "wall") {

        // bateu horizontalmente
        if (colRec.height >= colRec.width) {
            if (m->position.x >= colRec.x)
                m->position.x += colRec.width;
            else
                m->position.x -= colRec.width;

            self->getComponent<MovementComponent>()->direction.x *= -1;
        }

        // bateu verticalmente
        if (colRec.width >= colRec.height) {
            if (m->position.y >= colRec.y)
                m->position.y += colRec.height;
            else
                m->position.y -= colRec.height;

            self->getComponent<MovementComponent>()->direction.y *= -1;
        }
    }
    else if (tag == "paddle") {

        m->position.y = m->position.y - n->size.y;
        self->getComponent<MovementComponent>()->direction.y *= -1;
    }
}
