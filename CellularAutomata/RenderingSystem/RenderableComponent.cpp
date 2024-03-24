#include "RenderableComponent.h"

// Constructor
RenderableComponent::RenderableComponent(sf::Drawable& drawable, int renderLayer)
    : m_drawable(drawable), m_renderLayer(renderLayer) {}

// Getter for the drawable
sf::Drawable& RenderableComponent::getDrawable() {
    return m_drawable;
}

// Getter for the render layer
int RenderableComponent::getRenderLayer() const {
    return m_renderLayer;
}