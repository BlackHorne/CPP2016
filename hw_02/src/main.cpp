#include <stdio.h>
#include "Board.h"
#include "BoardView.h"
#include <string.h>

int main(int argc, char const *argv[])
{
	Board b;
	View v(b);
	if (argc > 1 && !strcmp(argv[1], "silent")) 
		v.Show(false);
	else
		v.Show(true);
	v.doGameCycle();
	return 0;
}