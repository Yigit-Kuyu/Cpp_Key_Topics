#include <iostream>

// Local variables have no linkage.
// Global variable and functions identifiers can have either internal linkage or external linkage.

// Internal linkage can be seen and used within a single translation unit,
// but it is not accessible from other translation units.
// This means that if two source files have identically named identifiers with internal linkage,
// those identifiers will be treated as independent (and do not result in an ODR violation for having duplicate definitions).



// set to internal linkage via the static keyword
static int g_x { 3 }; // Non-constant globals have external linkage by default, but can be given
                      // internal linkage via the static keyword.
                      // This separate internal g_x is only accessible within main.cpp.
// "static" means, static duration, which means they are created when the program starts
// and destroyed when the program ends.


const int g_y{ 1 }; // const globals have internal linkage by default,  don’t need the static keyword
constexpr int g_z{ 2 }; // constexpr globals have internal linkage by default,  don’t need the static keyword



static int add(int x, int y); // forward declaration for function add

int main()
{
    std::cout << g_x << '\n'; // uses main.cpp's g_x, prints 3

    //std::cout << add(3, 4) << '\n'; // Error, you cannot access static add function in a.cpp (different file)


    return 0;
}



// We’ll recommend a lighter-touch approach as a minimum:
// give internal linkage to any identifier that you have an reason to disallow access from other files.


// Related page: https://www.learncpp.com/cpp-tutorial/internal-linkage/
