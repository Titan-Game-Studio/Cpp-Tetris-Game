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
	int grid [20][10];

private:
	int numRows;
	int numClos;
	int cellSize;
	std::vector<Color> colors;
};

