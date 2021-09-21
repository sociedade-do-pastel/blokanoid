#include "../include/Paddle.hpp"

Paddle::Paddle()
{
}

Paddle::~Paddle()
{
}

void Paddle::init(Entity* e)
{
	m_entity = e;
    e->addComponent<TransformComponent>(GetScreenWidth() / 2,
                                        GetScreenHeight() - 20, 150, 10);
    e->addComponent<InputComponent>(inputHandler);
	e->addComponent<ColorComponent>(BLUE);
    e->addComponent<DrawComponent>();
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
