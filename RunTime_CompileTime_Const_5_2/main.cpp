#include <iostream>


int getNumber()
{
    std::cout << "Enter a number: ";
    int y=3;

    return y;

}


int main()
{
	const int x { 3 };  // x is a compile-time const
	const int y { 4 };  // y is a compile-time const
	const int x1 { 7 }; // x1 is now a compile-time constant

	const int z { x + y }; // x + y is a constant expression, so z is compile-time const

	const int y1 { getNumber() }; // y1 is a runtime constant

	std::cout << z << '\n';

	return 0;
}


// Related topic: https://www.learncpp.com/cpp-tutorial/constant-expressions-compile-time-const-and-runtime-const/
