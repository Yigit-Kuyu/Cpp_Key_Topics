#include "constants.h" // include all the forward declarations

#include <iostream>

// There is a method for constant global variables,
// we’ll define the constants in a .cpp file (to ensure the definitions only exist in one place),
// and put forward declarations in the header (which will be included by other files).


// Compile-time constants can typically be optimized more than runtime constants,
// the compiler may not be able to optimize these code as much.
// In order for variables to be usable in compile-time contexts, such as array sizes,
// the compiler has to see the variable’s definition (not just a forward declaration).
// This means these constants are now considered compile-time constants only
// within the file they are actually defined in (constants.cpp).
// Because the compiler compiles each source file individually, it can only see
// variable definitions that appear in the source file being compiled (which includes any included headers).
// For example, variable definitions in constants.cpp are not visible when the compiler compiles main.cpp

int main()
{
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/



