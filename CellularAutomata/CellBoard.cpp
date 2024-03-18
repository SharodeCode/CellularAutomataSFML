#include "CellBoard.h"

CellBoard::CellBoard(int ROWS, int COLUMNS, int CELL_SIZE) : ROWS(ROWS), COLUMNS(COLUMNS), CELL_SIZE(CELL_SIZE)
{
    initializeGrid();
}

// Function to initialize the grid with random cells
void CellBoard::initializeGrid() {
    for (int i = 0; i < ROWS; ++i) {
        std::vector<int> row(COLUMNS, 0);

        for (int j = 0; j < COLUMNS; ++j) {
            row[j] = rand() % 2; // Randomly set cells to alive (1) or dead (0)
        }

        grid.push_back(row);
    }
}

// Function to count the living neighbors of a cell
int CellBoard::countLivingNeighbors(int x, int y) {
    int count = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {

            if (i == 0 && j == 0) continue; // Skip the cell itself

            int col = (x + i + COLUMNS) % COLUMNS;
            int row = (y + j + ROWS) % ROWS;

            count += grid[row][col];
        }
    }

    return count;
}

// Function to update the grid according to the Game of Life rules
void CellBoard::updateGrid() {
    std::vector<std::vector<int>> newGrid = grid; // Copy the grid to update it based on the original state

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {

            int livingNeighbors = countLivingNeighbors(j, i);

            if (grid[i][j] == 1 && (livingNeighbors < 2 || livingNeighbors > 3)) {
                newGrid[i][j] = 0; // Die
            }

            else if (grid[i][j] == 0 && livingNeighbors == 3) {
                newGrid[i][j] = 1; // Become alive
            }
        }
    }

    grid = newGrid; // Update the original grid
}

void CellBoard::drawGrid(sf::RenderWindow* RenderWindow) {

    for (int i = 0; i < ROWS; ++i) {

        for (int j = 0; j < COLUMNS; ++j) {

            if (grid[i][j] == 1) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));

                cell.setPosition(j * CELL_SIZE, i * CELL_SIZE);
                cell.setFillColor(sf::Color::White); // Set cell color

                RenderWindow->draw(cell);
            }

        }

    }

}