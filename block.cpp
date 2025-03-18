#include "block.h"

Block::Block()
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
	rowOffset = 0;
	columOffset = 0;
}

void Block::Draw()
{
	std::vector<Position> tiles = GetCellPositions();
	for (Position item : tiles)
	{
		DrawRectangle(item.column * cellSize, item.row * cellSize, cellSize - 1, cellSize - 1, colors[id]);
	}
}

void Block::Move(int row, int colum)
{
	rowOffset += row;
	columOffset += colum;
}

std::vector<Position> Block::GetCellPositions()
{
	std::vector<Position> tiles = cells[rotationState];
	std::vector<Position> movedTiles;
	for (Position item : tiles)
	{
		Position newPos = Position(item.row + rowOffset, item.column + columOffset);
		movedTiles.push_back(newPos);
	}
	return movedTiles;
}
