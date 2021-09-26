#include "../include/CollisionComponent.hpp"

CollisionComponent::CollisionComponent(
    std::string tag,
    std::function<void(Entity*, std::string, Rectangle, Rectangle)> f)
    : m_tag(tag), m_callbackFunction(f)
{
}

CollisionComponent::~CollisionComponent()
{
    auto& v = m_owner->getManager()->collidableComponents;

    v.erase(std::remove_if(v.begin(), v.end(),
                           [this](auto e) { return e == this; }),
            v.end());
}

void CollisionComponent::init()
{
    m_owner->addComponent<TransformComponent>();
    m_transform = m_owner->getComponent<TransformComponent>();
    m_owner->getManager()->collidableComponents.push_back(this);
}

void CollisionComponent::update()
{
}

std::string CollisionComponent::getTag() const
{
    return m_tag;
}

Rectangle CollisionComponent::getRec() const
{
    return m_transform->getRec();
}

void CollisionComponent::executeCallback(std::string tag, Rectangle colRec,
                                         Rectangle otherRec)
{
    m_callbackFunction(m_owner, tag, colRec, otherRec);
}
