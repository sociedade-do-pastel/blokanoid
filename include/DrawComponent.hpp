#pragma once

#include <raylib.h>
#include "AbstractComponent.hpp"
#include "ColorCompoment.hpp"
#include "Manager.hpp"
#include "TransformComponent.hpp"

class DrawComponent : public AbstractComponent
{
public:
    DrawComponent();
    ~DrawComponent();

    void init() override;
    void update() override;

    void draw();

private:
    TransformComponent* m_transform{nullptr};
    ColorComponent* m_color{nullptr};
};
