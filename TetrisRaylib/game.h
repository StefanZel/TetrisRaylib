#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game 
{
public:
	Game();
	void Draw();
	void HandleInput();
	void MoveBlockDown();
	bool gameOver;
	int score;
private:
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	bool IsBlockOutside();
	void RotateBlock();
	void MoveBlockLeft();
	void MoveBlockLRight();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int LinesCleared,int moveDownPoints);
	Grid grid;
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
};