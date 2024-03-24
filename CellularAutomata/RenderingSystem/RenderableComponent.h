#pragma once

#include <SFML/Graphics.hpp>

class RenderableComponent
{
public:
    RenderableComponent(sf::Drawable& drawable, int renderLayer = 0);

    sf::Drawable& getDrawable();
    int getRenderLayer() const;

private:
    sf::Drawable& m_drawable;
    int m_renderLayer;
};

