#include <SFML/Graphics.hpp>
#include <vector>
#include "UI.h"
#include "CellBoard.h"

// Define the size of the window and cells
const int WINDOW_WIDTH = 1300;
const int WINDOW_HEIGHT = 1100;
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

    sf::Clock clock;
    sf::Clock fpsClock;
    float updateInterval = 0.5f; // Update the simulation every 0.1 seconds
    bool paused = false;
    float accumulator = 0.0f;



    UI ui = UI(&window);

    while (window.isOpen()) {
        sf::Time elapsed = fpsClock.restart();
        float deltaTime = elapsed.asSeconds();

        accumulator += deltaTime;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::P) {
                    paused = !paused; // Toggle pause state
                }

                if (event.key.code == sf::Keyboard::Up) {
                    updateInterval -= 0.1; // Speed up simulation
                }

                if (event.key.code == sf::Keyboard::Down) {
                    updateInterval += 0.1; // Slow down simulation
                }

            }
        }

        if (!paused && accumulator >= updateInterval) {
            accumulator = 0.0f;
            cellBoard.updateGrid();
            clock.restart();
        }

        window.clear();

        cellBoard.drawGrid(&window);
        ui.updateUI(deltaTime);

        window.display();
    }

    return 0;
}