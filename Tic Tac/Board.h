#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Move.h"

using namespace std;

class Board
{
public:
	Board(int N, int M)
	{
		table.resize(N);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
				table[i].push_back(-1);
		}
	}
	size_t getRows(void) { return table.size(); }
	size_t getCols(void) { return table.size() ? table[0].size() : -1; }
	int get(int i, int j) { return table[i][j]; }
	bool set(Move m, int flag)
	{
		if (table[m.getI()][m.getJ()] == -1)
		{
			if (flag == 0)
				table[m.getI()][m.getJ()] = 0;
			else
				table[m.getI()][m.getJ()] = 1;
			return true;
		}
		return false;
	}
	bool full(void)
	{
		for (size_t i = 0; i < table.size(); ++i)
		{
			for (size_t j = 0; j < table[i].size(); ++j)
				if (table[i][j] == -1)
					return false;
		}
		return true;
	}
	void print(void)
	{
		for (size_t i = 0; i < table.size(); ++i)
		{
			for (size_t j = 0; j < table[i].size(); ++j)
			{
				if (table[i][j] == -1)
					cout << "  ";
				if (table[i][j] == 0)
					cout << "   X ";
				if (table[i][j] == 1)
					cout << "   O ";
				if (j < 2)
					cout << "\t|";
			}		
			if(i < 2)
				cout << "\n -----------------------\n";
		}
	}
private:
	vector<vector<int>> table;
};
