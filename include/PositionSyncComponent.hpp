#pragma once

#include <functional>
#include "AbstractComponent.hpp"
#include "TransformComponent.hpp"

class PositionSyncComponent : public AbstractComponent
{
public:
    PositionSyncComponent(TransformComponent* source,
                          std::function<void(Entity*)> unsyncF);
    ~PositionSyncComponent();

    void init() override;
    void update() override;

private:
    TransformComponent* m_source{nullptr};
    TransformComponent* m_transform{nullptr};

    std::function<void(Entity*)> m_unsyncF;
};
