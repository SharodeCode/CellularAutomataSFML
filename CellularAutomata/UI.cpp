#include "UI.h"

UI::UI(sf::RenderWindow* RenderWindow)
{
    m_RenderWindow = RenderWindow;

    // Initialise font and text
    font.loadFromFile("./Media/Fonts/Roboto.ttf");
    textFPS.setFont(font);
    textFPS.setCharacterSize(20);
    textFPS.setFillColor(sf::Color::White);
    textFPS.setStyle(sf::Text::Regular);

    message_Text.setFont(font);
    message_Text.setCharacterSize(20);
    message_Text.setFillColor(sf::Color::White);
    message_Text.setStyle(sf::Text::Regular);
    message_Text.setPosition(0.0f, 20.0f);
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
    m_RenderWindow->draw(message_Text);
}

void UI::displayFPS(float fps)
{
    textFPS.setString("FPS: " + std::to_string(fps));
}

void UI::displayMessage(sf::String message)
{
    message_Text.setString("Message Output: " + message);
}
