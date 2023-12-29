#include "circle.h" // for BasicMath::pi
#include "growth.h" // for BasicMath::e

#include <iostream>


// The standard library makes extensive use of this feature, as each standard library header file
// contains its declarations inside a namespace std block contained within that header file.
// Otherwise the entire standard library would have to be defined in a single header file!
// Note that this capability also means you could add your own functionality to the std namespace.


// When you should use namespaces:
// In applications, namespaces can be used to separate application-specific code
// from code that might be reusable later (e.g. math functions). For example, physical and math functions
// could go into one namespace (e.g. Math::). Language and localization functions in another (e.g. Lang::).

// When you write a library or code that you want to distribute to others, always place your code inside a namespace.
// The code your library is used in may not follow best practices -- in such a case, if your library’s declarations
// aren’t in a namespace, there’s an elevated chance for naming conflicts to occur.


int main()
{
    std::cout << BasicMath::pi << '\n';
    std::cout << BasicMath::e << '\n';

    return 0;
}

// Related page: https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
