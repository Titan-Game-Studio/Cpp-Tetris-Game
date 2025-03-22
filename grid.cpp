#include "grid.h"
#include  <iostream>
#include "colors.h"

Grid::Grid()
{
	numRows = 20;
	numCols = 10;
	cellSize = 30;
	offset = 11;
	Inittialuze();
	colors = GetCellColors();
}

void Grid::Inittialuze()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int colum = 0; colum < numCols; colum++)
		{
			grid[row][colum] = 0;
		}
	}
}

void Grid::Print()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int colum = 0; colum < numCols; colum++)
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
		for (int colum = 0; colum < numCols; colum++)
		{
			int cellValue = grid[row][colum];

			int posX = colum * cellSize + offset;
			int posY = row * cellSize + offset;
			int  width = cellSize - 1;
			int height = cellSize - 1;
			Color color = colors[cellValue];

			DrawRectangle(posX, posY, width, height, color);
		}
	}
}

bool Grid::IsCellOutside(int row, int colum)
{
	if (row >= 0 && row < numRows && colum >= 0 && colum < numCols)
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

int Grid::ClearFullRows()
{
	int completed = 0;
	for (int row = numRows - 1; row >= 0; row--)
	{
		if (IsRowFull(row))
		{
			ClearRow(row);
			completed++;
		}
		else if (completed > 0)
		{
			MoveRowDown(row, completed);
		}
	}
	return completed;
}

bool Grid::IsRowFull(int row)
{
	for (int column = 0; column < numCols; column++)
	{
		if (grid[row][column] == 0)
		{
			return false;
		}
	}
	return true;
}

void Grid::ClearRow(int row)
{
	for (int column = 0; column < numCols; column++)
	{
		grid[row][column] = 0;
	}
}

void Grid::MoveRowDown(int row, int numRows)
{
	for (int column = 0; column < numCols; column++)
	{
		grid[row + numRows][column] = grid[row][column];
		grid[row][column] = 0;
	}
}
