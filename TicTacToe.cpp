#include <iostream>
#include <time.h>
#include "Game.h"
using namespace std;

char playerOne = 'X';
char playerTwo = 'O';
char playerOneName = ' ';
char playerTwoName = ' ';
char play;
int index;
bool win = false;
bool playerOneTurn = false;
bool moveOn = false;
bool ai;

int main()
{
	Game game;
	cout << "Insert '1' to play against an AI opponent.\nInsert '0' for multiplayer.\n";
	std::cin >> ai;
	game.ClearScreen();
	if (!ai)
	{
		while (playerOneName != playerOne || playerTwoName != playerTwo)
		{
			if (playerOneName != playerOne)
			{
				cout << "Player 1, " << "please choose symbol to play as:\n";
				std::cin >> playerOneName;
				if (playerOneName != ' ')
				{
					game.ClearScreen();
					playerOne = playerOneName;
					cout << "Player 1 plays as '" << playerOneName << "'\n\n";
				}
			}
			if (playerTwoName != playerTwo)
			{
				cout << "Player 2, " << "please choose symbol to play as:\n";
				std::cin >> playerTwoName;
				if (playerTwoName != ' ' && playerTwoName != playerOneName)
				{
					game.ClearScreen();
					playerTwo = playerTwoName;
					cout << "Player 1 plays as '" << playerOneName << "'\nPlayer 2 plays as '" << playerTwoName << "'\n\n";
				}
				else if (playerTwoName == playerOneName)
				{
					cout << "Player 2, " << " you can not have the same symbol as Player 1!\n";
				}
			}
		}
		while (!win)
		{
			playerOneTurn = !playerOneTurn;
			moveOn = false;
			while (!moveOn)
			{
				game.DisplayBoard();
				if (playerOneTurn)
				{
					cout << "Player 1's turn\n";
				}
				else
				{
					cout << "Player 2's turn\n";
				}
				cout << "Insert 1 to 9 to place your marker\n";
				std::cin >> index;
				game.Pause();
				game.ClearScreen();
				if (index < 1 || index > 9)
				{
					cout << "That is not a valid position\n";
					cout << "Please try again\n";
				}
				else if (game.CheckOccupied(playerOneName, playerTwoName, --index))
				{
					cout << "Position " << index + 1 << " is occupied\n";
					cout << "Please try again\n";
				}
				else
				{
					cout << "Player placed marker at position " << index + 1 << "\n";
					game.InsertMarker(playerOneName, playerTwoName, index, playerOneTurn);
					moveOn = true;
				}
			}
			win = game.CheckWin();
			if (win)
			{
				game.DisplayBoard();
				if (playerOneTurn)
				{
					cout << "Congratulations Player 1!\n"
						<< "You won!\n"
						<< "Play again?\n"
						<< "Insert Y for yes or N for no\n";
					std::cin >> play;
					if (play == 'y' || play == 'Y')
					{
						game.ResetBoard();
						win = false;
						game.ClearScreen();
					}
					else if (play == 'n' || play == 'N')
					{
						exit(0);
					}
				}
				else
				{
					cout << "Congratulations Player 2!\n"
						<< "You won!\n"
						<< "Play again?\n\n"
						<< "Insert Y for yes or N for no\n";
					std::cin >> play;
					if (play == 'y' || play == 'Y')
					{
						game.ResetBoard();
						win = false;
						game.ClearScreen();
					}
					else if (play == 'n' || play == 'N')
					{
						exit(0);
					}
				}
			}
			else if (game.CheckDraw())
			{
				game.DisplayBoard();
				cout << "Draw!\n"
					<< "Play again?\n"
					<< "Insert Y for yes or N for no\n";
				std::cin >> play;
				if (play == 'y' || play == 'Y')
				{
					game.ResetBoard();
					win = false;
					game.ClearScreen();
				}
				else if (play == 'n' || play == 'N')
				{
					exit(0);
				}
			}
		}
	}
	else
	{
		while (playerOneName != playerOne || playerTwoName == playerOneName)
		{
			if (playerOneName != playerOne)
			{
				cout << "Player 1, " << "please choose symbol to play as:\n";
				std::cin >> playerOneName;
				if (playerOneName != ' ')
				{
					game.ClearScreen();
					playerOne = playerOneName;
					cout << "Player 1 plays as '" << playerOneName << "'\n\n";
				}
			}
			if (playerTwoName != playerTwo || playerTwoName == playerOneName)
			{
				game.ClearScreen();
				playerTwoName = rand();
				srand(time(nullptr));
				playerTwoName = rand() % 93 + 33;
				playerTwo = playerTwoName;
				if (playerTwoName != playerOneName)
				{
					cout << "Player 1 plays as '" << playerOneName << "'\nAI opponent plays as '" << playerTwoName << "'\n\n";
				}
			}
		}
		while (!win)
		{
			playerOneTurn = !playerOneTurn;
			moveOn = false;
			while (!moveOn)
			{
				game.DisplayBoard();
				if (playerOneTurn)
				{
					cout << "Player 1's turn\n";
				}
				else
				{
					cout << "Player 2's turn\n";
				}
				cout << "Insert 1 to 9 to place your marker\n";
				std::cin >> index;
				game.Pause();
				game.ClearScreen();
				if (index < 1 || index > 9)
				{
					cout << "That is not a valid position\n";
					cout << "Please try again\n";
				}
				else if (game.CheckOccupied(playerOneName, playerTwoName, --index))
				{
					cout << "Position " << index + 1 << " is occupied\n";
					cout << "Please try again\n";
				}
				else
				{
					cout << "Player placed marker at position " << index + 1 << "\n";
					game.InsertMarker(playerOneName, playerTwoName, index, playerOneTurn);
					moveOn = true;
				}
			}
			win = game.CheckWin();
			if (win)
			{
				game.DisplayBoard();
				if (playerOneTurn)
				{
					cout << "Congratulations Player 1!\n"
						<< "You won!\n"
						<< "Play again?\n"
						<< "Insert Y for yes or N for no\n";
					std::cin >> play;
					if (play == 'y' || play == 'Y')
					{
						game.ResetBoard();
						win = false;
						game.ClearScreen();
					}
					else if (play == 'n' || play == 'N')
					{
						exit(0);
					}
				}
				else
				{
					cout << "Congratulations Player 2!\n"
						<< "You won!\n"
						<< "Play again?\n\n"
						<< "Insert Y for yes or N for no\n";
					std::cin >> play;
					if (play == 'y' || play == 'Y')
					{
						game.ResetBoard();
						win = false;
						game.ClearScreen();
					}
					else if (play == 'n' || play == 'N')
					{
						exit(0);
					}
				}
			}
			else if (game.CheckDraw())
			{
				game.DisplayBoard();
				cout << "Draw!\n"
					<< "Play again?\n"
					<< "Insert Y for yes or N for no\n";
				std::cin >> play;
				if (play == 'y' || play == 'Y')
				{
					game.ResetBoard();
					win = false;
					game.ClearScreen();
				}
				else if (play == 'n' || play == 'N')
				{
					exit(0);
				}
			}
		}
		game.Pause();
		//game.ClearScreen();
		cout << "Implement AI";
		game.Pause();
		exit(0);
	}
}
