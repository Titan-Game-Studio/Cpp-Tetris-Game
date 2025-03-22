#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
	Grid();
	void Inittialuze();
	void Print();
	void Draw();
	bool IsCellOutside(int row, int colum);
	bool IsCellEmpty(int row, int colum);
	int ClearFullRows();
	int grid [20][10];

private:
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int numRows);
	int numRows;
	int numCols;
	int cellSize;
	int offset;
	std::vector<Color> colors;
};

