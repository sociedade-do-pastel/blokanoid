#pragma once

#include "AbstractComponent.hpp"
#include "Entity.hpp"
#include "TransformComponent.hpp"

// foward declaration
class Entity;

class InputComponent : public AbstractComponent
{
public:
    InputComponent();
    ~InputComponent();

    void init() override;
    void update() override;

private:
	TransformComponent* transform{nullptr};
};
