#pragma once

#include <functional>
#include <raylib.h>
#include <string>
#include "AbstractComponent.hpp"
#include "Entity.hpp"
#include "TransformComponent.hpp"

class CollisionComponent : public AbstractComponent
{
public:
    CollisionComponent(std::string tag, std::function<void(Entity*, Entity*)> f);
    ~CollisionComponent();

    void init() override;
    void update() override;

	std::string getTag() const;
	
    void executeCallback(Entity* other);

private:
    std::string m_tag;
    std::function<void(Entity*, Entity*)> m_callbackFunction;
};
