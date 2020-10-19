#pragma once
class TicTacToe
{
private:
	char playerOneName;
	char playerTwoName;
	char emptyMarker = ' ';
	bool win = false;
	bool playerOneTurn = true;
	bool useAI = false;
	bool playerOneStart = true;
	void ShowGameOverScreen(Game& game, bool useAI, bool playerOneTurn);
	void ShowDrawScreen(Game& game);
	void AITurn(AI& ai, Game& game);
	char AISelectName();
	bool SelectMode();
	char HumanSelectName(bool playerOneTurn);
	void EndTurn();
	void ClearScreen();
	void HumanTurn(Game& game, bool playerOneTurn);
public:
	void Play();
};
