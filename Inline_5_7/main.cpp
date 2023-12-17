#include <iostream>
#include "pi.h"  // using first pi() function usage, if remove inline, will get error ( multiple definition of pi() )

double circumference(double radius); // forward declaration


// The compiler needs to be able to see the full definition of an inline function wherever it is used,
 // and all such definitions must be identical (or undefined behavior will result).


int main()
{
    std::cout << pi() << '\n';
    std::cout << circumference(2.0) << '\n';



    return 0;
}


// This is particularly useful for header-only libraries, which are one or more header files that implement
// some capability (no .cpp files are included). Header-only libraries are popular because there are no source files
// that need to be added to a project to use them and nothing that needs to be linked.
// You simply #include the header-only library and then can use it.



// Related link: https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/
