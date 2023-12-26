#include <iostream>

namespace constants
{
    inline constexpr double pi { 3.14159 };
}

using Degrees = double;
using Radians = double;

Degrees convertToRadians(double degrees)
{
    return degrees * constants::pi / 180;
}


int main()
{
    std::cout << "Enter a number of degrees: ";
    Degrees degrees{};
    std::cin >> degrees;

    Radians radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}

// Related page: https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/
