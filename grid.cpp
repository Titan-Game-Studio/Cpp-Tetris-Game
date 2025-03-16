#include "grid.h"
#include  <iostream>

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

std::vector<Color> Grid::GetCellColors()
{
	Color darkGrey = { 26, 31, 40, 255 };
	Color green = { 47, 230, 23, 255 };
	Color red = { 232, 18, 18, 255 };
	Color orange = { 226, 116, 17, 255 };
	Color yellow = { 237, 234, 4, 255 };
	Color purple = { 166, 0, 247, 255 };
	Color cyan = { 21, 204, 209, 255 };
	Color blue = { 13, 64, 216, 255 };
	Color lightBlue = { 59, 85, 162, 255 };
	Color darkBlue = { 44, 44, 127, 255 };

	return { darkGrey, green, red, orange, yellow, purple, cyan, blue };
}
