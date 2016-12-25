#include "NcursesBoardView.h"

	NcursesView::NcursesView(Board& board):b(board){};

	void NcursesView::NcursesShowBoard(){
		move(0, 0);
    	for (int i = 0; i < 10; i++){
    		for (int j = 0; j < 10; j++)
    			printw("%c", b.getCell(i, j));
    		printw("\n");
    	}
    }

    void NcursesView::NcursesDoGameCycle(){
    	
    	//Инициализируем X и Y - координаты поля в котором хотим совершить ход, а так же само игровое поле. 
    	int x = 0, y = 0, g = 0;
    	initscr();
    	noecho();
    	raw();

    	//Основной цикл игры.
    	while (b.isWin() == Board::GAME_IN_PROCESS){

    		//Ход ноликов.
    		while (true){
    			NcursesShowBoard();
    			printw("%s", "O move");
    			refresh();
    			move(x, y);
    			g = getch();
    			if (g == 120){
    				endwin();
    				return;
    			}

    			if (g == 65 && x > 0)
    				x--;

    			if (g == 66 && x < 9)
    				x++;

    			if (g == 67 && y < 9)
    				y++;

    			if (g == 68 && y > 0)
    				y--;

    			if (g == 32 && b.canMove(x, y, 'O')){
    				b.move(x, y, -1);
    				break;
    			}

    		}
    		
    		//Проверка, не закончилась ли игра.
    		if (b.isWin() != Board::GAME_IN_PROCESS)
    				break;

    		//Ход крестиков.
    		while (true){
    			NcursesShowBoard();
    			printw("%s", "X move");
    			refresh();
    			move(x, y);
    			g = getch();

    			if (g == 120){
    				endwin();
    				return;
    			}

    			if (g == 65 && x > 0)
    				x--;

    			if (g == 66 && x < 9)
    				x++;

    			if (g == 67 && y < 9)
    				y++;

    			if (g == 68 && y > 0)
    				y--;

    			if (g == 32 && b.canMove(x, y, 'X')){
    				b.move(x, y, 1);
    				break;
    			}
    		}


    	}
    	
    	//Вывод результатов.
    	NcursesShowBoard();
    	if (b.isWin() == Board::draw)
    		printw("Draw!\n");
    	if (b.isWin() == Board::x_wins)
    		printw("X wins!\n");
    	if (b.isWin() == Board::y_wins)
    		printw("O wins!\n");
    	printw("%s", "Press any button to exit.");
    	curs_set(0);
    	refresh();

    	//При нажатии любой клавиши, программа завершается.
    	getch();
    	endwin();
    }