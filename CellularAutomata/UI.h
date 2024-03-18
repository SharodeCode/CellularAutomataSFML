#pragma once
#include <SFML/Graphics.hpp>

class UI
{
public:
	UI(sf::RenderWindow*);
	void updateUI(float deltaTime);
	void displayFPS(float fps);

private:
	sf::RenderWindow* m_RenderWindow;
	sf::Text textFPS;
	sf::Font font;
	float displayFramerateTime = 0.0f;

};

