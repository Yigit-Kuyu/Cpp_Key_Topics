#include <iostream> // imports the declaration of std::cout


// It is not recommended to use " using directive" since variables, functions,.. can be conflicted with any identically named identifier in the std namespace.
using namespace std; // makes std::cout accessible as "cout" (using directive)
// rather remove "using namespace std" and
// access the variables in the name scape via scope resolution operator (::), such as std::cout


int cout() // defines our own "cout" function in the global namespace
{
    return 5;
}

int main()
{

   int x=cout();  // Compile error!  std has cout, name conflict with the identifier in the std namespace
    return 0;
}
