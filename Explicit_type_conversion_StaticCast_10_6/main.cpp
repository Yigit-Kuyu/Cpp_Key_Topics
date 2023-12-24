#include <iostream>



// static_cast is best used to convert one fundamental type into another.

int main()
{
    int x { 10 };
    int y { 4 };

    // static cast x to a double so we get floating point division
    double d { static_cast<double>(x) / y };
    std::cout << d << '\n'; // prints 2.5


    // Casting an int (2 or 4 bytes) to a char (1 byte) is potentially unsafe,
    // and so the compiler will typically print a warning.
    int i { 48 };
    // If we used list initialization, the compiler would yield a warning,
    // because the compiler can’t tell whether the integer value will overflow the range of the char or no.
    char ch {i}; // implicit narrowing conversion

    std::cout<< "char: " << ch << std::endl;



   // When we do this, we’re explicitly telling the compiler that this conversion is intended,
   // and we accept responsibility for the consequences, hence no warnings or errors.
   char ch1 { static_cast<char>(i) }; // explicit conversion from int to char, so that a char is assigned to variable ch.

   std::cout<< "char1: " << ch1 << std::endl;





    return 0;
}


// Note: The first example of the static_cast can be found in "Type_Conversion_4_12"
// Related Type: https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/
