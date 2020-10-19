#include "AI.h"
using namespace std;

bool AI::CheckFull(char (&gameBoard)[3][3])
{
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			if (gameBoard[i][j] == freeMarker)
			{
				return false;
			}
		}
	}
	return true;
}

bool AI::CheckWin(char (&gameBoard)[3][3], char player)
{
	for (unsigned int i = 0; i < 3; i++)
	{
		// Check rows
		if (gameBoard[i][0] != freeMarker)
		{
			if (gameBoard[i][0] == player && gameBoard[i][1] == player && gameBoard[i][2] == player)
			{
				return true;
			}
		}
		// Check columns
		if (gameBoard[0][i] != freeMarker)
		{
			if (gameBoard[0][i] == player && gameBoard[1][i] == player && gameBoard[2][i] == player)
			{
				return true;
			}
		}
	}
	// Check diagonals
	if (gameBoard[0][0] != freeMarker)
	{
		if (gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player)
		{
			return true;
		}
	}
	if (gameBoard[0][2] != freeMarker)
	{
		if (gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player)
		{
			return true;
		}
	}
	return false;
}

int AI::GetIndex(unsigned int firstIndex, unsigned int secondIndex)
{
	if (firstIndex == 0)
	{
		return firstIndex + secondIndex + 1;
	}
	else if (firstIndex == 1)
	{
		return firstIndex + secondIndex + 3;
	}	
	else //(firstIndex == 2)
	{
		return firstIndex + secondIndex + 5;
	}
}

int AI::MinSearch(char (&gameBoard)[3][3])
{
	if (CheckWin(gameBoard, humanPlayer))
	{
		return 10;
	}
	else if (CheckWin(gameBoard, aiPlayer))
	{
		return -10;
	}
	else if (CheckFull(gameBoard))
	{
		return 0;
	}
	int bestMoveScore = 100;
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			if (gameBoard[i][j] == freeMarker)
			{
				gameBoard[i][j] = aiPlayer;
				int tempMoveScore = MaxSearch(gameBoard);
				if (tempMoveScore <= bestMoveScore)
				{
					bestMoveScore = tempMoveScore;
				}
				gameBoard[i][j] = freeMarker;
			}
		}
	}
	return bestMoveScore;
}

int AI::MaxSearch(char(&gameBoard)[3][3])
{
	if (CheckWin(gameBoard, humanPlayer))
	{
		return 10;
	}
	else if (CheckWin(gameBoard, aiPlayer))
	{
		return -10;
	}
	else if(CheckFull(gameBoard))
	{
		return 0;
	}
	int bestMoveScore = -100;
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			if (gameBoard[i][j] == freeMarker)
			{
				gameBoard[i][j] = humanPlayer;
				int tempMoveScore = MinSearch(gameBoard);
				if (tempMoveScore >= bestMoveScore)
				{
					bestMoveScore = tempMoveScore;
				}
				gameBoard[i][j] = freeMarker;
			}
		}
	}
	return bestMoveScore;
}

AI::AI(char emptyMarker, char playerOneName, char playerTwoName)
{
	freeMarker = emptyMarker;
	humanPlayer = playerOneName;
	aiPlayer = playerTwoName;
}

int AI::MiniMax(char (&gameBoard)[3][3])
{
	int bestMoveScore = 100;
	unsigned int bestMove = 0;
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			if (gameBoard[i][j] == freeMarker)
			{
				gameBoard[i][j] = aiPlayer;
				int tempMoveScore = MaxSearch(gameBoard);
				if (tempMoveScore <= bestMoveScore)
				{
					bestMoveScore = tempMoveScore;
					bestMove = GetIndex(i, j);
				}
				gameBoard[i][j] = freeMarker;

			}
		}
	}
	return bestMove;
}
