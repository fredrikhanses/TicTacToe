#include <iostream>
#include "Game.h"
using namespace std;

Game::Game(char emptyMarker, char playerOneName, char playerTwoName)
{
	freeMarker = emptyMarker;
	humanPlayer = playerOneName;
	aiPlayer = playerTwoName;
}

void Game::DisplayBoard()
{
	cout << "_____________      _____________" << std::endl
		 << "| " << gameBoard[2][0] << " | " << gameBoard[2][1] << " | " << gameBoard[2][2] << " |      | 7 | 8 | 9 |" << std::endl
		 << "-------------      -------------" << std::endl
		 << "| " << gameBoard[1][0] << " | " << gameBoard[1][1] << " | " << gameBoard[1][2] << " |      | 4 | 5 | 6 |" << std::endl
		 << "-------------      -------------" << std::endl
		 << "| " << gameBoard[0][0] << " | " << gameBoard[0][1] << " | " << gameBoard[0][2] << " |      | 1 | 2 | 3 |" << std::endl
		 << "-------------      -------------" << std::endl;
}

void Game::ResetBoard()
{
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			gameBoard[i][j] = freeMarker;
		}
	}
}

int Game::GetFirstIndex(unsigned int index)
{
	if (index > 6)
	{
		return 2;
	}
	else if (index > 3 && index < 7)
	{
		return 1;
	}
	else //(index < 4)
	{
		return 0;
	}
}

int Game::GetSecondIndex(unsigned int index)
{
	if (index > 6)
	{
		return index - 7;
	}
	else if (index > 3 && index < 7)
	{
		return index - 4;
	}
	else //(index < 4)
	{
		return index - 1;
	}
}

void Game::InsertMarker(unsigned int index, bool playerOneTurn)
{
	unsigned int i = GetFirstIndex(index);
	unsigned int j = GetSecondIndex(index);
	if (playerOneTurn)
	{
		gameBoard[i][j] = humanPlayer;
	}
	else 
	{
		gameBoard[i][j] = aiPlayer;
	}
}

bool Game::CheckWin()
{
	for (unsigned int i = 0; i < 3; i++)
	{
		// Check horizontals
		if (gameBoard[i][0] != freeMarker)
		{
			if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2])
			{
				return true;
			}
		}
		// Check verticals
		if (gameBoard[0][i] != freeMarker)
		{
			if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i])
			{
				return true;
			}
		}
	}
	// Check diagonals
	if (gameBoard[0][0] != freeMarker)
	{
		if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2])
		{
			return true;
		}
	}
	if (gameBoard[0][2] != freeMarker)
	{
		if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0])
		{
			return true;
		}
	}
	return false;
}

bool Game::CheckOccupied(unsigned int index)
{
	unsigned int firstIndex = GetFirstIndex(index);
	unsigned int secondIndex = GetSecondIndex(index);
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			if (i == firstIndex && j == secondIndex)
			{
				if (gameBoard[i][j] == humanPlayer || gameBoard[i][j] == aiPlayer)
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Game::CheckFull()
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
