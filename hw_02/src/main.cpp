#include "Board.h"
#include "BoardView.h"
#include "NcursesBoardView.h"

#include <string.h>
#include <ncurses.h>

int main(int argc, char const *argv[])
{
	Board b;
	View v(b);
	NcursesView ncurses_v(b);
	v.Show(true);

	for (int i = 0; i < argc; i++){
		if (strcmp(argv[i], "silent") == 0)
			v.Show(false);
		if (strcmp(argv[i], "curses") == 0){
			ncurses_v.NcursesDoGameCycle();
			return 0;
		}
	}

	v.doGameCycle();
	return 0;
}