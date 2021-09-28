#include "../include/PositionSyncComponent.hpp"

PositionSyncComponent::PositionSyncComponent(
    TransformComponent* source, std::function<void(Entity*)> unsyncF)
    : m_source(source), m_unsyncF(unsyncF)
{
}

PositionSyncComponent::~PositionSyncComponent()
{
}

void PositionSyncComponent::init()
{
    m_owner->addComponent<TransformComponent>();
    m_transform = m_owner->getComponent<TransformComponent>();
}

void PositionSyncComponent::update()
{
	m_unsyncF(m_owner);
    Rectangle sourceRec = m_source->getRec();

    m_transform->position.x
        = sourceRec.x + sourceRec.width / 2 - m_transform->getRec().width / 2;
}
