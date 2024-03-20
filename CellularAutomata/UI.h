#pragma once
#include <SFML/Graphics.hpp>

class UI
{
public:
	UI(sf::RenderWindow*);
	void updateUI(float deltaTime);
	void displayFPS(float fps);
	void displayMessage(sf::String message);

private:
	sf::RenderWindow* m_RenderWindow;
	sf::Text textFPS;
	sf::Text message_Text;
	sf::Font font;
	float displayFramerateTime = 0.0f;

};

