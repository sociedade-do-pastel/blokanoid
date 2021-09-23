#include "../include/LayerComponent.hpp"
#include <iostream>
LayerComponent::LayerComponent(int layers) : layers(layers)
{
}

LayerComponent::~LayerComponent()
{
}

void LayerComponent::init()
{
    m_owner->addComponent<ColorComponent>(getLayerColor());
	m_colorComp = m_owner->getComponent<ColorComponent>();
}

void LayerComponent::update()
{
	m_colorComp->color = getLayerColor();
}

Color LayerComponent::getLayerColor()
{
    switch (layers) {
    case 1:
        return RED;
    case 2:
        return BLUE;
    case 3:
        return GREEN;
    case 4:
        return YELLOW;
    case 5:
        return PINK;
    default:
        return {0, 0, 0, 0};
    }
}
