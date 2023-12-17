#include <iostream>

using namespace std;

// Literals are values that are inserted directly into the code.


int main()
{
    float f { 4.1 }; // warning: 4.1 is a double literal, not a float literal
    // Because 4.1 has no suffix, the literal has type double, not float

    float f1 { 4.1f }; // use 'f' suffix so the literal is a float and matches variable type of float
    double d { 4.1 }; // change variable to type double so it matches the literal type double

    std::cout << 5.0 << '\n';  // 5.0 (no suffix) is type double (by default)
    std::cout << 5.0f << '\n'; // 5.0f is type float

    return 0;
}


// Related Topic: https://www.learncpp.com/cpp-tutorial/literals/
