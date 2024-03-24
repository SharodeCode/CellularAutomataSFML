#pragma once

#include <SFML/Graphics.hpp>
#include "RenderableComponent.h"

class RenderingSystem
{
public:
    RenderingSystem(sf::RenderWindow& window);

    void addRenderable(sf::Drawable* renderable);

    void render();

private:
    sf::RenderWindow& m_window;

    std::vector<sf::Drawable*> renderables;

    // Render a single renderable component
    void renderRenderable(RenderableComponent& renderable);
};

