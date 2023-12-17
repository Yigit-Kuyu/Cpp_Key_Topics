#include "constant.h"

#include <iostream>


//If you are using C++ 17 or more, you have better alternative than "Sharing_Global_Const_7.9"

int main()
{
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}






// Related page: https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/
