#include <iostream>
#include "pair.h"


// Note-1: This is the following part of "Structs_Class_Templates_13_11", because the topic 13.11 is long.

// Note-2: Just like function templates, class templates (or struct templates, same meaning) are typically defined in header files
// so they can be included into any code file that needs them. Both template definitions and type definitions are exempt from the one-definition rule,
// so this won’t cause problems.



void foo(); // forward declaration for function foo()

int main()
{
    Pair<double> p2 { 3.4, 5.6 };
    std::cout << max(p2) << " is larger\n";

    foo();

    return 0;
}


// Note: For multiple template types (template <typename T, typename U>), the C++ standard library contains
// a class template (or struct template, same meaning) named std::pair (in the <utility> header).



// Related page: https://www.learncpp.com/cpp-tutorial/class-templates/
