#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Move.h"
#include "Board.h"
#include "Player.h"
#include "AI.h"

class CleverAI :public AI
{
public:
	CleverAI(const int symbol) : AI(symbol) {}
	virtual Move chooseMove(Board& b)
	{
		for (size_t i = 0; i < b.getRows(); ++i)
		{
			for (size_t j = 0; j < b.getCols(); ++j)
				if (b.get(i, j) == -1)
					return Move(i, j, AI::getSymbol());
		}
	}
};
