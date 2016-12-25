#include "Board.h"
#include "BoardTest.h"

#define DO_CHECK(expr) check(expr, __FUNCTION__, __FILE__, __LINE__);

    void BoardTest::testgetChar1(){
        Board b;
        DO_CHECK(b.getChar(-1) == 'O');
    }

    void BoardTest::testgetChar2(){
        Board b;
        DO_CHECK(b.getChar(0) == '.');
    }

    void BoardTest::testgetChar3(){
        Board b;
        DO_CHECK(b.getChar(1) == 'X');
    }

    void BoardTest::testIsWin1() {
        Board b;
        b.move (1, 2, 1);
        b.move(2, 3, -1);
        b.move(4, 5, 1);
        DO_CHECK(b.isWin() == b.GAME_IN_PROCESS);
    }

    void BoardTest::testIsWin2() {
        Board b;
        b.move(4, 5, 1);
        b.move(4, 6, 1);
        b.move(4, 7, 1);
        b.move(4, 8, 1);
        b.move(4, 9, 1);
        DO_CHECK(b.isWin() == b.x_wins);
    }

    void BoardTest::testIsWin3() {
        Board b;
        b.move(6, 3, -1);
        b.move(7, 3, -1);
        b.move(8, 3, -1);
        b.move(9, 3, -1);
        b.move(5, 3, -1);
        DO_CHECK(b.isWin() == b.y_wins);
    }
    
    void BoardTest::testIsWin4() {
        Board b;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (i % 2 == j % 2)
                    b.move(i, j, 1);
                else
                    b.move(i, j, -1);
        DO_CHECK(b.isWin() == b.draw);
    }

    void BoardTest::testMove1() {
        Board b;
        b.move(5, 5, 1);
        BoardTest::DO_CHECK(b.getCell(5, 5) == 'X');
    }
    
    void BoardTest::testMove2() {
        Board b;
        b.move(2, 4, -1);
        BoardTest::DO_CHECK(b.getCell(2, 4) == 'O');
    }

    void BoardTest::testMove3() {
        Board b;
        b.move(6, 6, 1);
        b.move(6, 6, 0);
        b.move(6, 6, -1);
        DO_CHECK(b.getCell(6, 6) == 'O');
    }

    void BoardTest::testgetCell1(){
        Board b;
        b.move(0, 0, 1);
        DO_CHECK(b.getCell(0, 0) == 'X');
    }

    void BoardTest::testgetCell2(){
        Board b;
        b.move(3, 3, -1);
        DO_CHECK(b.getCell(3, 3) == 'O');
    }

    void BoardTest::testgetCell3(){
        Board b;
        DO_CHECK(b.getCell(4, 4) == '.');
    }

    void BoardTest::runAllTests() {
        testgetChar1();
        testgetChar2();
        testgetChar3();
        testIsWin1();
        testIsWin2();
        testIsWin3();
        testIsWin4();
        testMove1();
        testMove2();
        testMove3();
        testgetCell1();
        testgetCell2();
        testgetCell3();
    }