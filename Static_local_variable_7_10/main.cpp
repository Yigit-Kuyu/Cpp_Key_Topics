#include <iostream>


// Using the static keyword on a local variable changes its duration from automatic duration to static duration.
// This means the variable is now created at the start of the program,
// and destroyed at the end of the program (just like a global variable).
// As a result, the static variable will retain its value even after it goes out of scope!


void incrementAndPrint()
{
    int value{ 1 }; // automatic duration by default
    ++value;
    std::cout << value << '\n';
} // value is destroyed here

// Just like we use “g_” to prefix global variables,
// it’s common to use “s_” to prefix static (static duration) local variables.
void incrementAndPrint_static()
{
    static int s_value{1}; // static duration via static keyword.  This initializer is only executed once.
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out of scope

int main()
{
    incrementAndPrint(); // 2
    incrementAndPrint(); // 2
    incrementAndPrint(); // 2

    // Static local variables reinitialized the first time the variable definition is encountered.
    // The definition is skipped on subsequent calls, so no futher reinitialization happens.
    incrementAndPrint_static(); // 2
    incrementAndPrint_static(); // 3
    incrementAndPrint_static(); // 4

    return 0;
}

// Avoid static local variables unless the variable never needs to be reset.



// Related page: https://www.learncpp.com/cpp-tutorial/static-local-variables/
