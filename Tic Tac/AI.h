#pragma once
#include <vector>
#include <string>
#include "Move.h"
#include "Board.h"
class AI
{
public:
	AI(int symbol) : symbol(symbol) {}
	virtual Move chooseMove(Board& b) = 0;
	int getSymbol(void) { return symbol; }
	virtual ~AI() {};
private:
	int symbol;
};