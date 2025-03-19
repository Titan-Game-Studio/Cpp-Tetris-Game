#include "grid.h"
#include  <iostream>
#include "colors.h"

Grid::Grid()
{
	numRows = 20;
	numClos = 10;
	cellSize = 30;
	Inittialuze();
	colors = GetCellColors();
}

void Grid::Inittialuze()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int colum = 0; colum < numClos; colum++)
		{
			grid[row][colum] = 0;
		}
	}
}

void Grid::Print()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int colum = 0; colum < numClos; colum++)
		{
			std::cout << grid[row][colum] << " ";
		}
		std::cout << std::endl;
	}
}

void Grid::Draw()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int colum = 0; colum < numClos; colum++)
		{
			int cellValue = grid[row][colum];

			int posX = colum * cellSize + 1;
			int posY = row * cellSize + 1;
			int  width = cellSize - 1;
			int height = cellSize - 1;
			Color color = colors[cellValue];

			DrawRectangle(posX, posY, width, height, color);
		}
	}
}

bool Grid::IsCellOutside(int row, int colum)
{
	if (row >= 0 && row < numRows && colum >= 0 && colum < numClos)
	{
		return false;
	}

	return true;
}

bool Grid::IsCellEmpty(int row, int colum)
{
	if (grid[row][colum] == 0)
	{
		return true;
	}
	return false;
}
