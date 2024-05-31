#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
public:
	Block();
	void Draw(int offsetX, int offsetY);
	void Move(int rows, int columns);
	void Rotate();
	void UndoRotation();
	int id;
	std::map<int, std::vector<Position>> cells;
	std::vector<Position> GetCellPositions();
private:
	int cellSize;
	int rotationState;
	int rowOffset;
	int columnOffset;
	std::vector<Color> colors;

};