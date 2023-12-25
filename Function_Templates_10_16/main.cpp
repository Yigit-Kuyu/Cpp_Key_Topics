#include "add.h" // import the function template definition
#include <iostream>


void foo(int); // forward declaration for function foo

// The most conventional way to address the template
// is to put all your template code in a header (.h) file instead of a source (.cpp) file.


// You may be wondering why this doesn’t cause a violation of the one-definition rule (ODR). The ODR says that types, templates,
// inline functions, and inline variables are allowed to have identical definitions in different files.
// So there is no problem if the template definition is copied into multiple files (as long as each definition is identical).

int main()
{
    std::cout << addOne(1) << '\n';
    std::cout << addOne(2.3) << '\n';

    foo(5);

    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
