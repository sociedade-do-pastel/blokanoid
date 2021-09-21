#include "../include/Paddle.hpp"

Paddle::Paddle(Entity* e, Vector2 pos, Vector2 size) : m_entity(e)
{
    m_entity->addComponent<TransformComponent>(pos.x, pos.y, size.x, size.y);
    m_entity->addComponent<InputComponent>(inputHandler);
    m_entity->addComponent<CollisionComponent>("paddle", collisionCallback);
    m_entity->addComponent<ColorComponent>(BLUE);
    m_entity->addComponent<DrawComponent>();
}

Paddle::~Paddle()
{
}

void Paddle::inputHandler(TransformComponent* t)
{
    if (IsKeyDown(KEY_A))
        t->velocity.x = -1;
    else if (IsKeyDown(KEY_D))
        t->velocity.x = 1;
    else
        t->velocity.x = 0;
}

void Paddle::collisionCallback(Entity*self, Entity* other)
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
