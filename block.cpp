#include "block.h"

Block::Block()
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
	offset = 11;
	rowOffset = 0;
	columOffset = 0;
}

void Block::Draw()
{
	std::vector<Position> tiles = GetCellPositions();
	for (Position item : tiles)
	{
		int posX = item.column * cellSize + offset;
		int posY = item.row * cellSize + offset;
		int  width = cellSize - 1;
		int height = cellSize - 1;
		Color color = colors[id];
		DrawRectangle(posX, posY, width, height, color);
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

void Block::Rotate()
{
	rotationState++;
	if (rotationState == (int)cells.size())
	{
		rotationState = 0;
	}
}

void Block::UndoRotation()
{
	rotationState--;
	if (rotationState == -1)
	{
		rotationState = (int)cells.size();
	}
}
