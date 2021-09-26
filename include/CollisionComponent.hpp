#pragma once

#include <functional>
#include <raylib.h>
#include <string>
#include "AbstractComponent.hpp"
#include "Entity.hpp"
#include "Manager.hpp"
#include "TransformComponent.hpp"

class CollisionComponent : public AbstractComponent
{
public:
    CollisionComponent(
        std::string tag,
        std::function<void(Entity*, std::string, Rectangle, Rectangle)> f);
    ~CollisionComponent();

    void init() override;
    void update() override;

    std::string getTag() const;
    Rectangle getRec() const;

    void executeCallback(std::string tag, Rectangle colRec, Rectangle otherRec);

private:
    std::string m_tag;
    TransformComponent* m_transform{nullptr};
    std::function<void(Entity*, std::string, Rectangle, Rectangle)>
        m_callbackFunction;
};
