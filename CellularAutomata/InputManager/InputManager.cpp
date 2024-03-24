#include "InputManager.h"

class Controller;

InputManager::InputManager(sf::RenderWindow& window, Controller& controller) : window(window), controller(controller)
{

}

void InputManager::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        handleKeyboardInput(event);
        handleMouseInput(event);
    }
}

void InputManager::handleKeyboardInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::P) {
            controller.toggleSimulationPause(); // Toggle pause state
        }

        if (event.key.code == sf::Keyboard::Up) {
            controller.increaseSimulationSpeed(); // Speed up simulation
        }

        if (event.key.code == sf::Keyboard::Down) {
            controller.decreaseSimulationSpeed(); // Slow down simulation
        }
    }
}

void InputManager::handleMouseInput(const sf::Event& event) {
    // Handle mouse input if necessary
}