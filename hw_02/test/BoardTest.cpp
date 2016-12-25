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

    void BoardTest::testgetChar4(){
        Board b;
        DO_CHECK(b.getChar(12) == ' ');
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
        for (int i = -10; i < 20; i++)
            for (int j = -10; j < 20; j++)
                if (i % 2 == j % 2)
                    b.move(i, j, 1);
                else
                    b.move(i, j, -1);
        DO_CHECK(b.isWin() == b.draw);
    }

    void BoardTest::testIsWin5() {
        Board b;
        b.move(6, 3, -1);
        b.move(7, 3, -1);
        b.move(8, 3, -1);
        b.move(9, 3, -1);
        b.move(5, 3, -1);
        b.move(0, 1, 1);
        b.move(0, 2, 1);
        b.move(0, 3, 1);
        b.move(0, 4, 1);
        b.move(0, 5, 1);
        DO_CHECK(b.isWin() == b.y_wins);
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
        DO_CHECK(b.getCell(6, 6) == 'X');
    }

    void BoardTest::testMove4() {
        Board b;
        b.move(-1, -1, 1);
        b.move(6, 15, 0);
        b.move(6, 6, -1);
        DO_CHECK(b.getCell(6, 6) == 'O');
    }

    void BoardTest::testMove5() {
        Board b;
        for (int i = -10; i < 20; i++)
            for (int j = -10; j < 20; j++)
                b.move(i, j, 1);;
        DO_CHECK(b.getCell(0, 6) == '.');
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

    void BoardTest::testgetCell4(){
        Board b;
        DO_CHECK(b.getCell(-1, -1) == ' ');
    }

    void BoardTest::testcanMove1(){
        Board b;
        DO_CHECK(b.canMove(2, 2, 'r') == false)
    }

    void BoardTest::testcanMove2(){
        Board b;
        DO_CHECK(b.canMove(-2, -2, 'X') == false);
    }
    
    void BoardTest::testcanMove3(){
        Board b;
        DO_CHECK(b.canMove(15, 15, 'O') == false);
    }

    void BoardTest::testcanMove4(){
        Board b;
        b.move(1, 1, 1);
        DO_CHECK(b.canMove(1, 1, 'X') == false);
    }

    void BoardTest::testcanMove5(){
        Board b;
        DO_CHECK(b.canMove(2, 3, 'O') == true);
    }

    void BoardTest::runAllTests() {
        testgetChar1();
        testgetChar2();
        testgetChar3();
        testgetChar4();
        testIsWin1();
        testIsWin2();
        testIsWin3();
        testIsWin4();
        testIsWin5();
        testMove1();
        testMove2();
        testMove3();
        testMove4();
        testMove5();
        testgetCell1();
        testgetCell2();
        testgetCell3();
        testgetCell4();
        testcanMove1();
        testcanMove2();
        testcanMove3();
        testcanMove4();
        testcanMove5();
    }