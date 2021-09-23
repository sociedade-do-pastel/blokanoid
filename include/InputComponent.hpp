#pragma once

#include <functional>
#include <raylib.h>

#include "AbstractComponent.hpp"
#include "Entity.hpp"
#include "TransformComponent.hpp"

class InputComponent : public AbstractComponent
{
public:
    InputComponent(std::function<void(Entity*)> f);
    ~InputComponent();

    void init() override;
    void update() override;

private:
    TransformComponent* m_transform{nullptr};
    std::function<void(Entity*)> m_inputFunction;
};
