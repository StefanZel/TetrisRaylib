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
	Block currentBlock;
	Block nextBlock;
	bool IsBlockOutside();
	bool BlockFits();
	void RotateBlock();
	void MoveBlockLeft();
	void MoveBlockLRight();
	void LockBlock();
	void Reset();
	void UpdateScore(int LinesCleared,int moveDownPoints);
	Grid grid;
	std::vector<Block> blocks;
	std::vector<Block> GetAllBlocks();
};