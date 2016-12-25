#pragma once

#include "Board.h"

class View {
private:
	Board & b;
	bool sh;
public:   
	View(Board& board);
	void Show(bool f);
	void showBoard();
	void doGameCycle();
};