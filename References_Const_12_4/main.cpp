


#include <iostream>

int main()
{
    //int& y {10}; // error: can't bind to non-static object (non-modifiable)
    int x { 5 };          // x is a modifiable lvalue


    static int s_x { 6 };
    constexpr int& ref2 {s_x}; // ok, can bind to static local


    const int& ref { x }; // okay: we can bind a const reference to a modifiable lvalue

    std::cout << ref << '\n'; // okay: we can access the object through our const reference
    // ref = 7;                  // error: we can not modify an object through a const reference

    x = 6;                // okay: x is a modifiable lvalue, we can still modify it through the original identifier

    std::cout << "after x is changed: "<< ref << '\n'; // const ref is indirecly modified.
    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/
