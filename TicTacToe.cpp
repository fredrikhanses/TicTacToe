#include <iostream>
#include <time.h>
#include "AI.h"
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
bool useAI;

int main()
{
	Game game;
	AI ai;
	std::cout << "Insert '1' to play against an AI opponent.\nInsert '0' for multiplayer.\n";
	std::cin >> useAI;
	game.ClearScreen();
	/*Don't use AI*/
	if (!useAI)
	{
		/*Choose names*/
		while (playerOneName != playerOne || playerTwoName != playerTwo)
		{
			if (playerOneName != playerOne)
			{
				std::cout << "Player 1, " << "please choose symbol to play as:\n";
				std::cin >> playerOneName;
				if (playerOneName != ' ')
				{
					game.ClearScreen();
					playerOne = playerOneName;
					std::cout << "Player 1 plays as '" << playerOneName << "'\n\n";
				}
			}
			if (playerTwoName != playerTwo)
			{
				std::cout << "Player 2, " << "please choose symbol to play as:\n";
				std::cin >> playerTwoName;
				if (playerTwoName != ' ' && playerTwoName != playerOneName)
				{
					game.ClearScreen();
					playerTwo = playerTwoName;
					std::cout << "Player 1 plays as '" << playerOneName << "'\nPlayer 2 plays as '" << playerTwoName << "'\n\n";
				}
				else if (playerTwoName == playerOneName)
				{
					std::cout << "Player 2, " << " you can not have the same symbol as Player 1!\n";
				}
			}
		}
		/*Play*/
		while (!win)
		{
			playerOneTurn = !playerOneTurn;
			moveOn = false;
			while (!moveOn)
			{
				game.DisplayBoard();
				if (playerOneTurn)
				{
					std::cout << "Player 1's turn\n";
				}
				else
				{
					std::cout << "Player 2's turn\n";
				}
				std::cout << "Insert 1 to 9 to place your marker\n";
				std::cin >> index;
				game.Pause();
				game.ClearScreen();
				if (index < 1 || index > 9)
				{
					std::cout << "That is not a valid position\n";
					std::cout << "Please try again\n";
				}
				else if (game.CheckOccupied(playerOneName, playerTwoName, --index))
				{
					std::cout << "Position " << index + 1 << " is occupied\n";
					std::cout << "Please try again\n";
				}
				else
				{
					std::cout << "Player placed marker at position " << index + 1 << "\n";
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
					std::cout << "Congratulations Player 1!\n"
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
						std::exit(0);
					}
					else
					{
						win = false;
						game.ClearScreen();
					}
				}
				else
				{
					std::cout << "Congratulations Player 2!\n"
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
						std::exit(0);
					}
					else
					{
						win = false;
						game.ClearScreen();
					}
				}
			}
			else if (game.CheckFull())
			{
				game.DisplayBoard();
				std::cout << "Draw!\n"
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
					std::exit(0);
				}
				else
				{
					win = false;
					game.ClearScreen();
				}
			}
		}
	}
	/*Use AI*/
	else 
	{
		/*Choose names*/
		while (playerOneName != playerOne || playerTwoName == playerOneName)
		{
			if (playerOneName != playerOne)
			{
				std::cout << "Player 1, " << "please choose symbol to play as:\n";
				std::cin >> playerOneName;
				if (playerOneName != ' ')
				{
					game.ClearScreen();
					playerOne = playerOneName;
				}
			}
			if (playerTwoName != playerTwo || playerTwoName == playerOneName)
			{
				game.ClearScreen();
				srand(time(nullptr));
				playerTwoName = rand() % 93 + 33;
				playerTwo = playerTwoName;
				if (playerTwoName != playerOneName)
				{
					std::cout << "Player 1 plays as '" << playerOneName << "'\nAI opponent plays as '" << playerTwoName << "'\n\n";
				}
			}
		}
		/*Play*/
		while (!win)
		{
			playerOneTurn = !playerOneTurn;
			moveOn = false;
			while (!moveOn && !win)
			{
				if (playerOneTurn)
				{
					game.DisplayBoard();
					std::cout << "Player 1's turn\n";
					std::cout << "Insert 1 to 9 to place your marker\n";
					std::cin >> index;
					game.Pause();
					game.ClearScreen();
					if (index < 1 || index > 9)
					{
						std::cout << "That is not a valid position\n";
						std::cout << "Please try again\n";
					}
					else if (game.CheckOccupied(playerOneName, playerTwoName, --index))
					{
						std::cout << "Position " << index + 1 << " is occupied\n";
						std::cout << "Please try again\n";
					}
					else
					{
						std::cout << "Player placed marker at position " << index + 1 << "\n";
						game.InsertMarker(playerOneName, playerTwoName, index, playerOneTurn);
						moveOn = true;
					}
				}
				else /*AI Turn*/
				{
					std::cout << "Waiting for AI opponent.. \n";
					//srand(time(nullptr));
					//index = rand() % 8 + 1;
					//index = ai.MiniMax(game.pos, playerOneTurn, game);
					index = ai.FindBestPosition(game.pos, game, playerOneName, playerTwoName);
					//game.ClearScreen();
					std::cout << "AI opponent placed marker at position " << index + 1 << "\n";
					game.InsertMarker(playerOneName, playerTwoName, index, playerOneTurn);
					moveOn = true;
					//if (!game.CheckOccupied(playerOneName, playerTwoName, index))
					//{
					//	game.ClearScreen();
					//	std::cout << "AI opponent placed marker at position " << index + 1 << "\n";
					//	game.InsertMarker(playerOneName, playerTwoName, index, playerOneTurn);
					//	moveOn = true;
					//}
				}
			}
			win = game.CheckWin();
			if (win)
			{
				game.ClearScreen();
				if (playerOneTurn)
				{
					std::cout << "Congratulations Player 1!\n" << "You won against the AI!\n";
					game.DisplayBoard();
					std::cout << "Play again?\n" << "Insert Y for yes or N for no\n";
					std::cin >> play;
					if (play == 'y' || play == 'Y')
					{
						game.ResetBoard();
						win = false;
						game.ClearScreen();
					}
					else if (play == 'n' || play == 'N')
					{
						std::exit(0);
					}
					else
					{
						win = false;
						game.ClearScreen();
					}
				}
				else
				{
					std::cout << "You have been defeated by the AI!\n";
					game.DisplayBoard(); 
					std::cout << "Play again?\n\n" << "Insert Y for yes or N for no\n";
					std::cin >> play;
					if (play == 'y' || play == 'Y')
					{
						game.ResetBoard();
						win = false;
						game.ClearScreen();
					}
					else if (play == 'n' || play == 'N')
					{
						std::exit(0);
					}
					else
					{
						win = false;
						game.ClearScreen();
					}
				}
			}
			else if (game.CheckFull())
			{
				game.DisplayBoard();
				std::cout << "Draw!\n"
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
					std::exit(0);
				}
				else
				{
					win = false;
					game.ClearScreen();
				}
			}
		}
	}
	return 0;
}
