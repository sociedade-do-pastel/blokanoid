#pragma once

#include <raylib.h>
#include "AbstractComponent.hpp"

class ColorComponent : public AbstractComponent
{
public:
    ColorComponent(Color c);
    ~ColorComponent();

    void init() override;
    void update() override;

    Color color;
};
