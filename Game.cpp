#include <iostream>
#include "Game.h"
using namespace std;

void Game::DisplayBoard()
{
	cout << "_____________      _____________\n"
		 << "| " << pos[6] << " | " << pos[7] << " | " << pos[8] << " |      | 7 | 8 | 9 |\n"
		 << "-------------      -------------\n"
		 << "| " << pos[3] << " | " << pos[4] << " | " << pos[5] << " |      | 4 | 5 | 6 |\n"
		 << "-------------      -------------\n"
		 << "| " << pos[0] << " | " << pos[1] << " | " << pos[2] << " |      | 1 | 2 | 3 |\n"
		 << "-------------      -------------\n";
}

void Game::ResetBoard()
{
	int i = 0;
	for (char character : pos)
	{
		pos[i] = ' ';
		i++;
	}
}

void Game::InsertMarker(char team1, char team2, int index, bool playerOneTurn)
{
	if (playerOneTurn)
	{
		pos[index] = team1;
	}
	else 
	{
		pos[index] = team2;
	}
}

bool Game::CheckWin()
{
	if (pos[0] != ' ')
	{
		if ((pos[0] == pos[1] && pos[0] == pos[2]) || (pos[0] == pos[3] && pos[0] == pos[6]) || (pos[0] == pos[4] && pos[0] == pos[8]))
		{
			return true;
		}
	}
	if (pos[1] != ' ')
	{
		if ((pos[1] == pos[4] && pos[1] == pos[7]))
		{
			return true;
		}
	}
	if (pos[3] != ' ')
	{
		if ((pos[3] == pos[4] && pos[3] == pos[5]))
		{
			return true;
		}
	}
	if (pos[8] != ' ')
	{
		if ((pos[8] == pos[7] && pos[8] == pos[6]) || (pos[8] == pos[5] && pos[8] == pos[2]))
		{
			return true;
		}
	}
	return false;
}

bool Game::CheckOccupied(char team1, char team2, int index)
{
	int i = 0;
	for (char character : pos)
	{
		if (i == index)
		{
			if (pos[i] == team1 || pos[i] == team2)
			{
				return true;
			}
		}
		i++;
	}
	return false;
}

bool Game::CheckDraw()
{
	for (char character : pos)
	{
		if (character == ' ')
		{
			return false;
		}
	}
	return true;
}

void Game::Pause()
{
	std::cin.clear();
	std::cin.ignore();
}

void Game::ClearScreen()
{
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}
