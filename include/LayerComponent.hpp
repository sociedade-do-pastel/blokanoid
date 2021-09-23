#pragma once

#include "AbstractComponent.hpp"
#include "Components.hpp"

class LayerComponent : public AbstractComponent
{
public:
    LayerComponent(int layers);
    ~LayerComponent();

    void init() override;
    void update() override;

    Color getLayerColor();

    int layers;

private:
    ColorComponent* m_colorComp{nullptr};
};
