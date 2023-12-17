#include <iostream>


// ++x -->	Increment x, then return x
// x++ -->	Copy x, then increment x, then return the copy


int main()
{

    int x { 5 };
    int y { ++x }; // x is incremented to 6, x is evaluated to the value 6, and 6 is assigned to y

    std::cout << x << ' ' << y << '\n'; // output: 6, 6

    int x1 { 5 };
    int y1 { x1++ }; // x is incremented to 6, copy of original x is evaluated to the value 5, and 5 is assigned to y

    std::cout << x1 << ' ' << y1 << '\n'; // output: 6, 5
    return 0;


    // Related page: https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/


    return 0;
}
