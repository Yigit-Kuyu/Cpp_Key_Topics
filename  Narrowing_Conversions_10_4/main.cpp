#include <iostream>

// Because they can be unsafe and are a source of errors, avoid narrowing conversions whenever possible.
// If you need to perform a narrowing conversion, use static_cast to convert it into an explicit conversion.


void someFcn(int i)
{
}

int main()
{

    //int i { 3.5 }; // Error: Narrowing conversions are disallowed when using brace initialization.
    int i { static_cast<int>(3.5) }; // want to do a narrowing conversion inside a brace initialization, use static_cast.



    double d{ 5.0 };

    someFcn(d); // bad: implicit narrowing conversion will generate compiler warning

    // good: we're explicitly telling the compiler this narrowing conversion is intentional
    someFcn(static_cast<int>(d)); // no warning generated

    return 0;
}





// Related page: https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/
