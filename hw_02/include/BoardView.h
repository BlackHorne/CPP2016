#pragma once

#include "Board.h"

class View {
private:
	Board & b;
	bool show; //Переменная, отвечающая за то, нужно ли выводить поле после каждого хода.

public:   
	View(Board& board);
	void Show(bool f);
	void showBoard();
	void doGameCycle();
};