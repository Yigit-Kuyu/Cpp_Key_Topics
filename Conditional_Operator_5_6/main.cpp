#include <iostream>

using namespace std;

int main()


// c ? x : y	If conditional c is true then evaluate x, otherwise evaluate y

 {
    constexpr bool inBigClassroom { false };

    if (inBigClassroom)
        int classSize { 30 };
    else
        int classSize { 20 };

    //std::cout << "The class size is: " << classSize;  // Error, because
                                                      // variables defined inside an if-statement or else-statement
                                                      // die at the end of the if-statement or else-statement.

    int x { 2 };
    int y { 1 };
    int z { (10 - x) > y ? x : y };
    std::cout << z; // 2


    // The type of the expressions must match or be convertible
    std::cout << (true ? 1 : 2) << '\n';    // okay: both operands have matching type int
    std::cout << (false ? 1 : 2.2) << '\n'; // okay: int value 1 converted to double

    std::cout << (true ? -1 : 2u) << '\n';  // surprising result: -1 converted to unsigned int, result out of range,
                                            // use an if-else statement

    return 0;
}

// Related Topic: https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
