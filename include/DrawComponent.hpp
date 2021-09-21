#pragma once

#include <raylib.h>
#include "AbstractComponent.hpp"
#include "TransformComponent.hpp"
#include "ColorCompoment.hpp"

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
