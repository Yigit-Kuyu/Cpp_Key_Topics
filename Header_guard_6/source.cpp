#include "square.h"

int getSquareSides() // actual definition for getSquareSides
{
    return 4;
}


int getSquarePerimeter(int sideLength)
{
    return sideLength * getSquareSides();
}

// Related lesson: https://www.learncpp.com/cpp-tutorial/header-guards/
