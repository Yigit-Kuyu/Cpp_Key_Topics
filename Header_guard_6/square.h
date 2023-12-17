#ifndef SQUARE_H
#define SQUARE_H

// In order to call a function defined in another file, you must place a forward declaration.
//  The forward declaration tells the compiler about the existence of the function.

int getSquareSides(); // forward declaration for getSquareSides
int getSquarePerimeter(int sideLength); // forward declaration for getSquarePerimeter

#endif
