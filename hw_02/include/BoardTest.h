#pragma once

#include "Test.h"

class BoardTest: public Test {
public:
	void DO_CHECK(bool expr);
	void runAllTests();
	void testgetChar1();
    void testgetChar2();
    void testgetChar3();
    void testIsWin1();
    void testIsWin2();
    void testIsWin3();
    void testIsWin4();
    void testMove1();
    void testMove2();
    void testMove3();
    void testgetCell1();
    void testgetCell2();
    void testgetCell3();
};