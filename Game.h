#pragma once
class Game
{
public:
	Game(char emptyMarker, char playerOneName, char playerTwoName);
	void DisplayBoard();
	void InsertMarker(unsigned int index, bool playerOneTurn);
	void ResetBoard();
	bool CheckWin();
	bool CheckOccupied(unsigned int index);
	bool CheckFull();
public:
	char gameBoard[3][3] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
private:
	int GetFirstIndex(unsigned int index);
	int GetSecondIndex(unsigned int index);
	char freeMarker;
	char humanPlayer;
	char aiPlayer;
};
