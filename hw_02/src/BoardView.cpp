#include "BoardView.h"
 	
 	View::View(Board& board):b(board){};

    void View::Show(bool f){
    	show = f;
    }

    void View::showBoard(){
    	for (int i = 0; i < 10; i++){
    		for (int j = 0; j < 10; j++)
    			printf("%c", b.getCell(i, j));
    		printf("\n");
    	}
    }

    void View::doGameCycle(){
    	//X и Y - переменные, в которые считываем ход.
    	int x, y;

    	//Основной цикл игры.
    	while (b.isWin() == Board::GAME_IN_PROCESS){

    		if (show) showBoard();
    		
    		//Ход ноликов.
    		while (true){
    			printf("%s", "O move: ");
    			if (scanf("%d%d", &x, &y) > 0){
    				if (x == -1 && y == -1)
    					return;
    				if (!b.canMove(x, y, 'O'))
    					printf("%s\n", "Bad move!");
    				else{
    					b.move(x, y, -1);
    					printf("\n");
    					break;
    				}
    			}
    		}

    		if (show) showBoard();

    		//Проверка, не закончилась ли игра.
    		if (b.isWin() != Board::GAME_IN_PROCESS)
    			break;

    		//Ход крестиков.
    		while (true){
    			printf("%s", "X move: ");
    			if (scanf("%d%d", &x, &y) > 0){
    				if (x == -1 && y == -1)
    					return;
    				if (!b.canMove(x, y, 'X'))
    					printf("%s\n", "Bad move!");
    				else{
    					b.move(x, y, 1);
    					printf("\n");
    					break;
    				}
    			}
    		}

    	}

    	//Вывод результатов игры.
    	showBoard();
    	if (b.isWin() == Board::draw)
    		printf("Draw!\n");
    	if (b.isWin() == Board::x_wins)
    		printf("X wins!\n");
    	if (b.isWin() == Board::y_wins)
    		printf("O wins!\n");
    	return;
    }; 