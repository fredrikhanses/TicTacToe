#include <iostream>
#include <sstream>
#include <time.h>
#include "AI.h"
#include "Game.h"
#include "TicTacToe.h"
using namespace std;

int main()
{
	TicTacToe ticTacToe;
	ticTacToe.Play();
	return 0;
}

void TicTacToe::Play()
{
	playerOneName = emptyMarker;
	playerTwoName = emptyMarker;
	useAI = SelectMode();
	if (playerOneName == emptyMarker)
	{
		playerOneName = HumanSelectName(playerOneTurn);
		EndTurn();
	}
	if (playerTwoName == emptyMarker)
	{
		if (useAI)
		{
			playerTwoName = AISelectName();
		}
		else
		{
			playerTwoName = HumanSelectName(playerOneTurn);
		}
		EndTurn();
	}
	Game game(emptyMarker, playerOneName, playerTwoName);
	AI ai(emptyMarker, playerOneName, playerTwoName);
	while (!win)
	{
		if (useAI && !playerOneTurn)
		{
			AITurn(ai, game);
		}
		else
		{
			HumanTurn(game, playerOneTurn);
		}
		win = game.CheckWin();
		if (win)
		{
			ClearScreen();
			ShowGameOverScreen(game, useAI, playerOneTurn);
		}
		else if (game.CheckFull())
		{
			ShowDrawScreen(game);
		}
		EndTurn();
	}
}

void TicTacToe::ShowGameOverScreen(Game& game, bool useAI, bool playerOneTurn)
{
	char answer;
	string winningPlayer;
	string defeatedPlayer;
	if (useAI)
	{
		if (playerOneTurn)
		{
			winningPlayer = "Player 1!";
			defeatedPlayer = "Mr AI!";
		}
		else
		{
			winningPlayer = "Mr AI!";
			defeatedPlayer = "Player 1!";
		}
	}
	else
	{
		if (playerOneTurn)
		{
			winningPlayer = "Player 1!";
			defeatedPlayer = "Player 2!";
		}
		else
		{
			winningPlayer = "Player 2!";
			defeatedPlayer = "Player 1!";
		}
	}
	std::cout << "Congratulations " << winningPlayer << std::endl << "You won against " << defeatedPlayer << std::endl;
	game.DisplayBoard();
	std::cout << "Play again?" << std::endl <<"Insert Y for yes or N for no" << std::endl;
	std::cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		playerOneStart = !playerOneStart;
		game.ResetBoard();
		win = false;
		ClearScreen();
	}
	else if (answer == 'n' || answer == 'N')
	{
		std::exit(0);
	}
	else
	{
		ClearScreen();
		ShowGameOverScreen(game, useAI, playerOneTurn);
	}
}

void TicTacToe::ShowDrawScreen(Game& game)
{
	char answer;
	game.DisplayBoard();
	std::cout << "Draw!" << std::endl
		<< "Play again?" << std::endl
		<< "Insert Y for yes or N for no" << std::endl;
	std::cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		playerOneStart = !playerOneStart;
		game.ResetBoard();
		win = false;
		ClearScreen();
	}
	else if (answer == 'n' || answer == 'N')
	{
		std::exit(0);
	}
	else
	{
		ClearScreen();
		ShowDrawScreen(game);
	}
}

void TicTacToe::AITurn(AI& ai, Game& game)
{
	unsigned int index;
	index = ai.MiniMax(game.gameBoard);
	ClearScreen();
	std::cout << "AI opponent placed marker at position " << index << std::endl;
	game.InsertMarker(index, playerOneTurn);
}

char TicTacToe::AISelectName()
{
	char AIName;
	ClearScreen();
	srand(time(nullptr));
	AIName = rand() % 93 + 33;
	if (AIName != playerOneName)
	{
		std::cout << "Player 1 plays as '" << playerOneName << "'\nAI opponent plays as '" << AIName << "'" << std::endl << std::endl;
		return AIName;
	}
	else
	{
		return AISelectName();
	}
}

bool TicTacToe::SelectMode()
{
	string mode;
	std::cout << "Insert '1' to play against an AI opponent." << std::endl << "Insert '2' for multiplayer." << std::endl;
	std::cin >> mode;
	if (mode == "1" || mode == "2")
	{
		ClearScreen();
		if (mode == "1")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		ClearScreen();
		std::cout << "Mode '" << mode << "' is invalid" << std::endl;
		return SelectMode();
	}
}

void TicTacToe::HumanTurn(Game& game, bool playerOneTurn)
{
	unsigned int index;
	game.DisplayBoard();
	std::cout << "Player " << !playerOneTurn + 1 << "'s turn" << std::endl;
	std::cout << "Insert 1 to 9 to place your marker" << std::endl;
	std::cin >> index;
	ClearScreen();
	if (index < 1 || index > 9)
	{
		std::cout << index << " is not a valid position" << std::endl;
		std::cout << "Please try again" << std::endl;
		HumanTurn(game, playerOneTurn);
	}
	else if (game.CheckOccupied(index))
	{
		std::cout << "Position " << index << " is occupied" << std::endl;
		std::cout << "Please try again" << std::endl;
		HumanTurn(game, playerOneTurn);
	}
	else
	{
		std::cout << "Player " << !playerOneTurn + 1 << " placed marker at position " << index << std::endl;
		game.InsertMarker(index, playerOneTurn);
	}
}

char TicTacToe::HumanSelectName(bool playerOneTurn)
{
	char playerName;
	string player;
	if (playerOneTurn)
	{
		player = "Player 1";
	}
	else
	{
		player = "Player 2";
	}
	std::cout << player << ", please choose symbol to play as:" << std::endl;
	std::cin >> playerName;
	string restofline;
	getline(cin, restofline);
	if (playerName != ' ' && playerName != playerOneName)
	{
		ClearScreen();
		std::cout << player << " plays as '" << playerName << "'" << std::endl << std::endl;
		return playerName;
	}
	else
	{
		ClearScreen();
		std::cout << player << ", '" << playerName << "' is an invalid name!" << std::endl;
		return HumanSelectName(playerOneTurn);
	}
}

void TicTacToe::EndTurn()
{
	playerOneTurn = !playerOneTurn;
}

void TicTacToe::ClearScreen()
{
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
	system("clear");
#endif
}
