#include <SFML/Graphics.hpp>
#include <vector>
#include "UI.h"
#include "CellBoard.h"
#include "GameController/Controller.h"
#include "InputManager/InputManager.h"
#include "RenderingSystem/RenderingSystem.h"

// Define the size of the window and cells
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 800;
constexpr int FRAME_RATE = 60;
const int CELL_SIZE = 10;

// Calculate the number of cells in each dimension
const int COLUMNS = WINDOW_WIDTH / CELL_SIZE;
const int ROWS = WINDOW_HEIGHT / CELL_SIZE;

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game of Life");

void drawGrid(sf::RenderWindow& window) {
    int i;
    sf::Vertex verticalLine[2];
    sf::Vertex horizontalLine[2];

    // Set color for grid lines
    sf::Color gridColor = sf::Color(200, 200, 200); // Light gray

    // Draw vertical lines
    for (i = 0; i <= COLUMNS; ++i) {
        verticalLine[0] = sf::Vertex(sf::Vector2f(i * CELL_SIZE, 0), gridColor);
        verticalLine[1] = sf::Vertex(sf::Vector2f(i * CELL_SIZE, WINDOW_HEIGHT), gridColor);
        window.draw(verticalLine, 2, sf::Lines);
    }

    // Draw horizontal lines
    for (i = 0; i <= ROWS; ++i) {
        horizontalLine[0] = sf::Vertex(sf::Vector2f(0, i * CELL_SIZE), gridColor);
        horizontalLine[1] = sf::Vertex(sf::Vector2f(WINDOW_WIDTH, i * CELL_SIZE), gridColor);
        window.draw(horizontalLine, 2, sf::Lines);
    }
}

static void initialise() {

    window.setFramerateLimit(FRAME_RATE);
}

int main() {

    CellBoard cellBoard(ROWS, COLUMNS, CELL_SIZE);

    sf::Clock fpsClock;

    UI ui(&window);
    Controller controller(cellBoard, ui);
    InputManager inputManager(window, controller);
    RenderingSystem renderingSystem(window);

    while (window.isOpen()) {
        sf::Time elapsed = fpsClock.restart();
        float deltaTime = elapsed.asSeconds();

        inputManager.processEvents();
        controller.update(deltaTime);

        window.clear();

        cellBoard.drawGrid(&window);

        //renderingSystem.render();

        window.display();
    }

    return 0;
}