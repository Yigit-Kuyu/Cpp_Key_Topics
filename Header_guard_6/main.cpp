#include "square.h" // square.h is also included once here
#include <iostream>

// The forward declaration tells the compiler about the existence of the function.

// "square.h" 'ı import etmeden, forward declarationları global olarakta yazabilirsin:
//int getSquareSides(); // forward declaration for getSquareSides
//int getSquarePerimeter(int sideLength); // forward declaration for getSquarePerimeter

int main()
{
    std::cout << "a square has " << getSquareSides() << " sides\n";
    std::cout << "a square of length 5 has perimeter length " << getSquarePerimeter(5) << '\n';


    return 0;
}



// Related lesson: https://www.learncpp.com/cpp-tutorial/header-guards/
