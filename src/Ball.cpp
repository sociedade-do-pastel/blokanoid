#include "../include/Ball.hpp"

void Ball::makeEntity(Entity* e, int x, int y, int w, int h, float speed,
                      Color color)
{
    e->addComponent<TransformComponent>(x, y, w, h);
    e->addComponent<MovementComponent>(Vector2{1, -1}, speed);
    e->addComponent<CollisionComponent>("ball", collisionCallback);
    e->addComponent<ColorComponent>(color);
    e->addComponent<DrawComponent>();
}

void Ball::collisionCallback(Entity* self, std::string tag, Rectangle colRec,
                             Rectangle otherRec)
{
    auto m = self->getComponent<TransformComponent>();
	
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
        m->position.y -= colRec.height;
        self->getComponent<MovementComponent>()->direction.y *= -1;
    }
}
