#include <iostream>

extern int g_x; // this extern is a forward declaration of a variable named g_x that is defined somewhere else
extern const int g_y; // this extern is a forward declaration of a const variable named g_y that is defined somewhere else

// Note that function forward declarations don’t need the extern keyword but
// Variables forward declarations do need the extern keyword


int main()
{
    std::cout << g_x << ' ' << g_y << '\n'; // prints 2 3

    return 0;
}


// An identifier with external linkage can be seen and used
// both from the file in which it is defined, and from other code files (via a forward declaration).


// The related page: https://www.learncpp.com/cpp-tutorial/external-linkage-and-variable-forward-declarations/
