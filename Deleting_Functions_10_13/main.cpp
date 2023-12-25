#include <iostream>


// In cases where we have a function that we explicitly do not want to be callable,
// we can define that function as deleted by using the = delete specifier.
// If the compiler matches a function call to a deleted function, compilation will be halted with a compile error.



void printInt(int x)
{
    std::cout << x << '\n';
}

// = delete means “I forbid this”, not “this doesn’t exist”.

void printInt(char) = delete; // calls to this function will halt compilation
void printInt(bool) = delete; // calls to this function will halt compilation

int main()
{
    printInt(5);    // okay: prints 5
    printInt('a');  // ıf dont use delete, it will prints 97 - does this make sense? --> with delete, compile error: function deleted
    printInt(true); // ıf dont use delete, it will prints 1 - does this make sense?  --> with delete, compile error: function deleted

    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/deleting-functions/
