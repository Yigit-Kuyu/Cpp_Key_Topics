#include <iostream>

int add(int x, int y); // forward declaration of add() (using a function declaration)
// alternative: int add(int, int); // valid function declaration


int main()
{

    int num { add(3, 4) }; // initialize num with the return value of add(3, 4)
    std::cout << "The sum of 3 and 4 is: " << num << '\n'; // this works because we forward declared add() above
    return 0;
}

int add(int x, int y) // even though the body of add() isn't defined until here
{
    return x + y;
}
