#pragma once
#include "Game.h"
class AI
{
private:
	int MiniMax(char board[9], int depth, bool AITurn, Game game, char playerOneName, char playerTwoName);
	int CheckWin(char pos[9], char playerOneName, char playerTwoName);
public:
	int FindBestPosition(char board[9], Game game, char playerOneName, char playerTwoName);
};

