#include <iostream>
#include "AI.h"
using namespace std;

int AI::CheckWin(char pos[9], char playerOneName, char playerTwoName)
{
	if (pos[0] != ' ')
	{
		if ((pos[0] == pos[1] && pos[0] == pos[2]) || (pos[0] == pos[3] && pos[0] == pos[6]) || (pos[0] == pos[4] && pos[0] == pos[8]))
		{
			if (pos[0] == playerOneName)
			{
				return 10;
			}
			else if (pos[0] == playerTwoName)
			{
				return -10;
			}
		}
	}
	if (pos[4] != ' ')
	{
		if ((pos[4] == pos[3] && pos[4] == pos[5]) || (pos[4] == pos[1] && pos[4] == pos[7]) || (pos[4] == pos[6] && pos[4] == pos[2]))
		{
			if (pos[4] == playerOneName)
			{
				return 10;
			}
			else if (pos[4] == playerTwoName)
			{
				return -10;
			}
		}
	}
	if (pos[8] != ' ')
	{
		if ((pos[8] == pos[7] && pos[8] == pos[6]) || (pos[8] == pos[5] && pos[8] == pos[2]))
		{
			if (pos[8] == playerOneName)
			{
				return 10;
			}
			else if (pos[8] == playerTwoName)
			{
				return -10;
			}
		}
	}
	return 0;
}

// This is the minimax function. It considers all 
// the possible ways the game can go and returns 
// the value of the board 
int AI::MiniMax(char pos[9], int depth, bool isMax, Game game, char playerOneName, char playerTwoName)
{
	int score = CheckWin(pos, playerOneName, playerTwoName);

	// If Maximizer or Minimizer has won the game return his/her evaluated score 
	if (score == 10 || score == -10)
	{
		return score;
	}
	// If there are no more moves and no winner then it is a tie 
	else if (game.CheckFull())
	{
		return 0;
	}

	// If this maximizer's move 
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells 
		for (int i = 0; i < 9; i++)
		{
			// Check if cell is empty 
			if (pos[i] == ' ')
			{
				// Make the move 
				pos[i] = playerOneName;

				// Call minimax recursively and choose the maximum value 
				int current = MiniMax(pos, depth + 1, !isMax, game, playerOneName, playerTwoName);
				if (current > best)
				{
					best = current;
				}

				// Undo the move 
				pos[i] = ' ';
			}
		}
		return best;
	}

	// If this minimizer's move 
	else
	{
		int best = 1000;

		// Traverse all cells 
		for (int i = 0; i < 9; i++)
		{
			// Check if cell is empty 
			if (pos[i] == ' ')
			{
				// Make the move 
				pos[i] = playerTwoName;

				// Call minimax recursively and choose the minimum value
				int current = MiniMax(pos, depth + 1, !isMax, game, playerOneName, playerTwoName);
				if (current < best)
				{
					best = current;
				}

				// Undo the move 
				pos[i] = ' ';
			}
		}
		return best;
	}
}

// This will return the best possible move for the player 
int AI::FindBestPosition(char pos[9], Game game, char playerOneName, char playerTwoName)
{
	int bestValue = -1000;
	int bestIndex = -1;

	// Traverse all cells, evaluate minimax function for 
	// all empty cells. And return the cell with optimal value. 
	for (int i = 0; i < 9; i++)
	{
		std::cout << "board[" << i << "] is: " << pos[i] << "\n";
		// Check if cell is empty 
		if (pos[i] == ' ')
		{
			// Make the move 
			pos[i] = playerOneName;

			// compute evaluation function for this move. 
			int currentValue = MiniMax(pos, 0, false, game, playerOneName, playerTwoName);

			// Undo the move 
			pos[i] = ' ';

			// If the value of the current move is 
			// more than the best value, then update best
			if (currentValue > bestValue)
			{
				bestIndex = i;
				bestValue = currentValue;
			}
		}	
	}
	std::cout << "bestValue is: " << bestValue << "\n";
	std::cout << "bestIndex is: " << bestIndex << "\n";
	return bestIndex;
}