#include <iostream>


// For those of you already familiar with pointers,
// the ampersand(&)in this context does not mean “address of”, it means “lvalue reference to”.


int main()
{
    //int& invalidRef;   // error: references must be initialized

    // When defining a reference, place the ampersand next to the type (not the reference variable’s name):
    // Good usage: int& ref   Bad usage: int &ref --> All of them are acceptable.

    int x { 5 };    // x is a normal integer variable
    int& ref { x }; // ref is now an alias for variable x

    std::cout << x << ref << '\n'; // print 55
    x = 6; // x now has value 6
    std::cout << x << ref << '\n'; // prints 66


    ref = 7; // the object being referenced (x) now has value 7
    std::cout << x << ref << '\n'; // prints 77




    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/lvalue-references/
