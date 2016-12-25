#pragma once

#include <string.h>
#include <stdio.h>

class Test {
protected:
    static int failedNum;
    static int totalNum;  
public:
	
	static void DO_CHECK(bool expr);

	static void check(bool expr, const char *func, const char  *filename, size_t lineNum);

	static void showFinalResult();

	virtual void runAllTests() =0;
};