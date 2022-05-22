#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Move.h"
#include "Board.h"
#include "Player.h"
#include "AI.h"
#include "CleverAI.h"

enum GameStatus { IN_PROGRESS, X_WON, O_WON, DRAW };

class Game
{
public:
	Game(int difficulty, string name, char symbol) : board(3, 3), player(name, symbol), status(IN_PROGRESS)
	{
		pAI = new CleverAI(1);
	}
	void makeMovePlayer() { player.chooseMove(board); }
	void makeMoveAI()
	{
		Move m = pAI->chooseMove(board);
		board.set(m, 1);
	}
	GameStatus getStatus(void) { return status; }
	void setStatus(GameStatus gameStatus) { status = gameStatus; }
	Board& getBoard(void) { return board; }
	void printBoard(void) { return board.print(); }
	~Game() { delete pAI; }
private:
	Board board;
	Player player;
	AI* pAI;
	GameStatus status;
};