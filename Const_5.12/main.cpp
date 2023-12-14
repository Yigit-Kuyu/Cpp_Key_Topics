#include <iostream>

#define MY_NAME "YcK"  // object-like macros with substitution text (not preferable)

void printInt(const int x) //  the value of the argument in the function call will be used as the initializer for x.
{
    std::cout << "const value: " << x << '\n';
}


int main()
{
    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    const int constAge { age }; // initialize const variable using non-const value

    age = 5;      // ok: age is non-const, so we can change its value
    // constAge = 6; // error: constAge is const, so we cannot change its value


    printInt(age);

    std::cout << "My name is: " << MY_NAME << '\n';


    return 0;
}

// Related topic: https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/
