#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
public:
	Block();
	void Draw();
	void Move(int row, int colum);
	std::vector<Position> GetCellPositions();
	void Rotate();
	void UndoRotation();
	int id;
	std::map<int, std::vector<Position>> cells;
private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
	int offset;
	int rowOffset;
	int columOffset;
};

