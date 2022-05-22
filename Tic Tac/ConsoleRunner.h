#pragma once

class ConsoleRunner
{
public:
	ConsoleRunner(int difficulty, string name, char symbol) : game(difficulty, name, symbol) {}
	void play(void)
	{
		cout << "\n    Tic Tac Toe Game\n\n\n";
		bool playerTurn = true;
		while (!game.getBoard().full() && victory(game.getBoard()) == -1)
		{
			if (playerTurn)
				game.makeMovePlayer();
			else
				game.makeMoveAI();
			playerTurn = (playerTurn == true) ? false : true;
			if (game.getBoard().full())
				game.setStatus(GameStatus::DRAW);
			else if (victory(game.getBoard()) == 0)
				game.setStatus(GameStatus::O_WON);
			else if (victory(game.getBoard()) == 1)
				game.setStatus(GameStatus::X_WON);
		}	
	}
	int victory(Board& b)
	{

		if (game.getBoard().get(0, 0) == 1 && game.getBoard().get(0, 1) == 1 && game.getBoard().get(0, 2) == 1 ||
			game.getBoard().get(1, 0) == 1 && game.getBoard().get(1, 1) == 1 && game.getBoard().get(1, 2) == 1 ||
			game.getBoard().get(2, 0) == 1 && game.getBoard().get(2, 1) == 1 && game.getBoard().get(2, 2) == 1 ||
			game.getBoard().get(0, 0) == 1 && game.getBoard().get(1, 0) == 1 && game.getBoard().get(2, 0) == 1 ||
			game.getBoard().get(0, 1) == 1 && game.getBoard().get(1, 1) == 1 && game.getBoard().get(2, 1) == 1 ||
			game.getBoard().get(0, 2) == 1 && game.getBoard().get(1, 2) == 1 && game.getBoard().get(2, 2) == 1 ||
			game.getBoard().get(0, 0) == 1 && game.getBoard().get(1, 1) == 1 && game.getBoard().get(2, 2) == 1 ||
			game.getBoard().get(0, 2) == 1 && game.getBoard().get(1, 1) == 1 && game.getBoard().get(2, 0) == 1)
			return 1;
		if (game.getBoard().get(0, 0) == 0 && game.getBoard().get(0, 1) == 0 && game.getBoard().get(0, 2) == 0 ||
			game.getBoard().get(1, 0) == 0 && game.getBoard().get(1, 1) == 0 && game.getBoard().get(1, 2) == 0 ||
			game.getBoard().get(2, 0) == 0 && game.getBoard().get(2, 1) == 0 && game.getBoard().get(2, 2) == 0 ||
			game.getBoard().get(0, 0) == 0 && game.getBoard().get(1, 0) == 0 && game.getBoard().get(2, 0) == 0 ||
			game.getBoard().get(0, 1) == 0 && game.getBoard().get(1, 1) == 0 && game.getBoard().get(2, 1) == 0 ||
			game.getBoard().get(0, 2) == 0 && game.getBoard().get(1, 2) == 0 && game.getBoard().get(2, 2) == 0 ||
			game.getBoard().get(0, 0) == 0 && game.getBoard().get(1, 1) == 0 && game.getBoard().get(2, 2) == 0 ||
			game.getBoard().get(0, 2) == 0 && game.getBoard().get(1, 1) == 0 && game.getBoard().get(2, 0) == 0)
			return 0;
		return -1;
	}
	void printResult(void)
	{
		if (game.getStatus() == GameStatus::DRAW)
			cout << "Draw!\n";
		else if (game.getStatus() == GameStatus::O_WON)
		{
			cout << "\n\tX Won!\n\n";
			game.getBoard().print();
		}
		else
		{
			cout << "\n\tO Won!\n\n";
			game.getBoard().print();
		}
	}
private:
	Game game;
};