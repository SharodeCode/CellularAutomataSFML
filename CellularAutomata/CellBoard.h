#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class CellBoard
{
public:
	CellBoard(int ROWS, int COLUMNS, int CELLL_SIZE);

	void initializeGrid();
	int countLivingNeighbors(const std::vector<std::vector<int>>& grid, int x, int y);
	void updateGrid();
	void drawGrid(sf::RenderWindow* RenderWindow);

private:
	std::vector<std::vector<int>> grid;
	int COLUMNS;
	int ROWS;
	int CELL_SIZE = 10;
};

