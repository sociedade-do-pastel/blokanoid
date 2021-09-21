#include "../include/Wall.hpp"

Wall::Wall(Entity* e, Vector2 pos, Vector2 size)
    : m_entity(e), m_pos(pos), m_size(size)
{
    m_entity->addComponent<TransformComponent>(m_pos.x, m_pos.y, m_size.x,
                                               m_size.y);
    m_entity->addComponent<CollisionComponent>("wall", collisionCallback);
    m_entity->addComponent<ColorComponent>(PURPLE);
    m_entity->addComponent<DrawComponent>();
}

Wall::~Wall()
{
}

void Wall::collisionCallback(Entity* self, Entity* other)
{
    return;
}
