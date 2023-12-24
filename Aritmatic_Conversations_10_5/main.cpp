#include <iostream>
#include <typeinfo> // for typeid()

int main()
{

    int i{ 2 };
    double d{ 3.5 };

    // In this case, the double operand has the highest priority,
    // so the lower priority operand (of type int) is type converted to double value 2.0.
    std::cout << typeid(i + d).name() << ' ' << i + d << '\n'; // show us the type of i + d

    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/arithmetic-conversions/
