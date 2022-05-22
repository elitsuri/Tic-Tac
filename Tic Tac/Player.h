#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Move.h"
#include "Board.h"

class Player
{
public:
	Player(string name, int symbol) : name(name)
	{
		symbol = (symbol == '0') ? 0 : 1;
	}
	string& getName(void) { return name; }
	int getSymbol(void) { return symbol; }
	void chooseMove(Board& b)
	{
		int i{}, j{};
		do
		{
			b.print();
			cout << endl;
			cout << "\n\n  Enter Row Choice: ";
			cin >> i;
			cout << "  Enter Cols Choice: ";
			cin >> j;
			cout << endl;

		} while (!b.set(Move(i, j, symbol), 0));
	}
private:
	string name;
	int symbol = 0;
};

