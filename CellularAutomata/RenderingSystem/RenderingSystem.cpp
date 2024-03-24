#include "RenderingSystem.h"

RenderingSystem::RenderingSystem(sf::RenderWindow& window) : m_window(window) {}

void RenderingSystem::render() {
    // Clear window
    m_window.clear();

    // TODO: Optionally, perform sorting, culling, and batching
    //sortRenderables(renderables);
    //cullRenderables(renderables);
    //batchRenderables(renderables);


    // Render each renderable component
    for (sf::Drawable* renderable : renderables) {
        m_window.draw(*renderable);
    }

    // Display rendered frame
    m_window.display();
}

void RenderingSystem::addRenderable(sf::Drawable* renderable) {
    renderables.push_back(renderable);
}

void RenderingSystem::renderRenderable(RenderableComponent& renderable) {
    m_window.draw(renderable.getDrawable());
}