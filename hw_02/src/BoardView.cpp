#include "BoardView.h"
#include "Board.h"
 	
 	View::View(Board& board):b(board){};

    void View::Show(bool f){
    	sh = f;
    }

    void View::showBoard(){
    	for (int i = 0; i < 10; i++){
    		for (int j = 0; j < 10; j++)
    			printf("%c", b.getCell(i, j));
    		printf("\n");
    	}
    }
    void View::doGameCycle(){
    	int x, y;
    	while (b.isWin() == Board::GAME_IN_PROCESS){
			if (sh) showBoard();
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
    		if (sh) showBoard();
    		if (b.isWin() != Board::GAME_IN_PROCESS)
    			break;
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
    	showBoard();
    	if (b.isWin() == Board::draw)
    		printf("Draw!\n");
    	if (b.isWin() == Board::x_wins)
    		printf("X wins!\n");
    	if (b.isWin() == Board::y_wins)
    		printf("O wins!\n");
    }; 