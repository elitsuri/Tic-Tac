#include <iostream>
#include <vector>
#include <string>
#include "Move.h"
#include "Board.h"
#include "Player.h"
#include "AI.h"
#include "CleverAI.h"
#include "Game.h"
#include "ConsoleRunner.h"
using namespace std;

int main(void)
{
	ConsoleRunner consoleRunner(1, "gsamaras", 'X');
	consoleRunner.play();
	consoleRunner.printResult();

	cin.get(); cin.get();
	return 0;
}