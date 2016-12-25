#pragma once

#include <stdio.h>

class  Board {
private:
	int** table;
	enum cell {O = -1, dot = 0, X = 1};
	
public:
	enum state {GAME_IN_PROCESS = 0, x_wins, y_wins, draw};
	
	Board();

	~Board();

	char getChar(int sign);

	char getCell(int x, int y);

    void move(int x, int y, int sign);

    bool canMove(int x, int y, char sign);

    state isWin();
};