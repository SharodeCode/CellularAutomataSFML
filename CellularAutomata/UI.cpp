#include "UI.h"

UI::UI(sf::RenderWindow* RenderWindow)
{
    m_RenderWindow = RenderWindow;

    // Initialise font and text
    font.loadFromFile("./Media/Fonts/Roboto.ttf");
    textFPS.setFont(font);
    textFPS.setCharacterSize(10);
    textFPS.setFillColor(sf::Color::White);
    textFPS.setStyle(sf::Text::Regular);
}


void UI::updateUI(float deltaTime) {

    // Update framerate
    displayFramerateTime += deltaTime;
    float fps = 1.0f / (deltaTime);

    if (displayFramerateTime > 0.5)
    {
        displayFPS(fps);
        displayFramerateTime = 0;
    }

    m_RenderWindow->draw(textFPS);
}

void UI::displayFPS(float fps)
{
    textFPS.setString("FPS: " + std::to_string(fps));
}
