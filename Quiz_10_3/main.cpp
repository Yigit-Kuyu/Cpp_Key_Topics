#include <iostream>


// Note: This function gives an error due to misusing function overloading

void print()
{
    std::cout << "void\n";
}


void print(int x=9)  // Dont use initial value in default arguments for function overloading
{
    std::cout << "int " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    print(5.0f);
    // parameters with default arguments aren’t counted for resolving overloaded functions,
    // the compiler can’t tell whether the call to print() should resolve to print() or print(int x=0)
    print(); // Error
    print(10);

    return 0;
}

// Related page: https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/
