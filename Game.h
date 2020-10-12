#ifndef Game_H
#define Game_H
class Game
{
public:
	void DisplayBoard();
	void InsertMarker(char team1, char team2, int index, bool playerOneTurn);
	void ResetBoard();
	bool CheckWin();
	bool CheckOccupied(char team1, char team2, int index);
	bool CheckFull();
	void Pause();
	void ClearScreen();
public:
	char pos[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
};
#endif