#pragma once

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Graphics.hpp>
#include "../GameController/Controller.h"
#include "../UI.h"

class InputManager {
public:
    InputManager(sf::RenderWindow& window, Controller& controller);
    void processEvents();

private:
    void handleKeyboardInput(const sf::Event& event);
    void handleMouseInput(const sf::Event& event);
    sf::RenderWindow& window;
    Controller& controller;
    bool paused = false;
    float updateInterval = 0.5f; // Default update interval
};

#endif