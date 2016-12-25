#include <ncurses.h>
#include "Board.h"

class NcursesView {
private:
	Board & b;

public:
	NcursesView(Board& board);
	void NcursesShowBoard();
	void NcursesDoGameCycle();
};