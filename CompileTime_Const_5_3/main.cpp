#include <iostream>


//  We can enlist the compiler’s help to ensure we get a compile-time const where we desire one.
// To do so, we use the constexpr keyword instead of const in a variable’s declaration.
// A constexpr (which is short for “constant expression”) variable can only be a compile-time constant.
int five()
{
// Normal function calls are evaluated at runtime,

    return 5;
}

int main()
{

    constexpr double gravity { 9.8 }; // ok: 9.8 is a constant expression
    constexpr int sum { 4 + 5 };      // ok: 4 + 5 is a constant expression
    constexpr int something { sum };  // ok: sum is a constant expression

    int x { 3 + 4 }; // 3 + 4 may evaluate at compile-time or runtime
    std::cout << x << '\n';    // this is a runtime expression



    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    //constexpr int myAge { age };      // compile error: age is not a constant expression
    //constexpr int f { five() };       // compile error: return value of five() is not a constant expression

    return 0;
}

// Related topic: https://www.learncpp.com/cpp-tutorial/constexpr-variables/
