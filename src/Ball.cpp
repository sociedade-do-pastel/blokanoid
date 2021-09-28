#include "../include/Ball.hpp"

float Ball::speed      = 0;
bool Ball::ballRunning = false;

void Ball::makeEntity(Entity* e, int x, int y, int w, int h, float speed,
                      Color color)
{
    e->addComponent<TransformComponent>(x, y, w, h);
    e->addComponent<CollisionComponent>("ball", collisionCallback);
    e->addComponent<ColorComponent>(color);
    e->addComponent<DrawComponent>();
    Ball::speed = speed;
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
        else if (colRec.width >= colRec.height) {
            if (m->position.y >= colRec.y)
                m->position.y += colRec.height;
            else
                m->position.y -= colRec.height;

            self->getComponent<MovementComponent>()->direction.y *= -1;
        }
    }
    else if (tag == "paddle") {
        m->position.y -= colRec.height;

        auto move = self->getComponent<MovementComponent>();

        if (move->direction.x == 0) {
            int sectionSize = otherRec.width / 3;
            if (m->getCenter().x <= otherRec.x + sectionSize)
                move->direction = Vector2{-1, -1};
            else if (m->getCenter().x <= otherRec.x + 2 * sectionSize)
                move->direction.y *= -1;
            else if (m->getCenter().x <= otherRec.x + 3 * sectionSize)
                move->direction = Vector2{1, -1};
        }
        else
            move->direction.y *= -1;
    }
}

void Ball::unsyncFunc(Entity* self)
{
    if (IsKeyPressed(KEY_SPACE)) {
        self->addComponent<MovementComponent>(Vector2{0, -1}, Ball::speed);
        self->removeComponent(self->getComponent<PositionSyncComponent>());
        Ball::ballRunning = true;
    }
}
