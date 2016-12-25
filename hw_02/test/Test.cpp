#include "Test.h"
    
    int Test::failedNum = 0;
    int Test::totalNum = 0;

    void Test::check(bool expr, const char *func, const char  *filename, size_t lineNum){
    	if (!expr){
    		failedNum++;
    		printf("%s in %s:%d\n", func , filename , (int)lineNum);
    	}
    	totalNum++;
    };

    void Test::showFinalResult(){
    	if (failedNum == 0)
    		printf("%s\n", "All tests passed");
    	else
    		printf("%s %d %s %d %s\n", "Failed", failedNum, "of", totalNum, "tests");
    };