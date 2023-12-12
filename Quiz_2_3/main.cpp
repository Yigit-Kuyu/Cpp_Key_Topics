#include <iostream>
#include "read.h"
#include "write.h"


void writeAnswer(int t)
{
    std::cout<< t << std::endl;
}

int readNumber(int x, int y)
{
    return x + y;
}


int main()
{
    int total;
    total=readNumber(3,2);
    writeAnswer(total);

    return 0;
}


// Related link: https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/
