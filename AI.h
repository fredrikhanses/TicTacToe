#pragma once
class AI
{
private:
	bool CheckFull(char (&gameBoard)[3][3]);
	int MinSearch(char (&gameBoard)[3][3]);
	int MaxSearch(char (&gameBoard)[3][3]);
	bool CheckWin(char (&gameBoard)[3][3], char player);
	int GetIndex(unsigned int firstIndex, unsigned int secondIndex);
	char freeMarker;
	char humanPlayer;
	char aiPlayer;
public:
	AI(char emptyMarker, char playerOneName, char playerTwoName);
	int MiniMax(char (&gameBoard)[3][3]);
};
