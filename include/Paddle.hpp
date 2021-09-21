#pragma once

#include "Components.hpp"
#include "Entity.hpp"

class Paddle
{
public:
    Paddle();
    ~Paddle();

	void init(Entity* e);
    static void inputHandler(TransformComponent* t);

private:
    Entity* m_entity{nullptr};
};
