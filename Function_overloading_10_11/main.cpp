#include <iostream>


// Note: The code is only for explanation, so will not work.


int add(int x, int y)  // Function overloading can be performed via parameter type.
{
    return x + y;
}

int add(int x, int y, int z) // unction overloading can be performed via number of parameters.
{
    return x + y + z;
}


// Function overloading is not performed via return parameter.
// (The return type of a function is not considered for differentiation)
/*
int getRandomValue() {}; // Error
double getRandomValue() {}; // Error
*/



int main()
{

    // Overloading based on type of parameters:

    int add(int x, int y); // integer version
    // For parameters passed by value, the const qualifier is also not considered.
    int add(const int x, const int y); //  not differentiated from int add(int x, int y)

    double add(double x, double y); // floating point version
    double add(int x, double y); // mixed version
    double add(double x, int y); // mixed version


    return 0;
}


/*

When the compiler compiles a function, it performs name mangling, which means the compiled name of the function is altered (“mangled”)
based on various criteria, such as the number and type of parameters, so that the linker has unique names to work with.
For example, some function with prototype int fcn() might compile to name __fcn_v, whereas int fcn(int) might compile to name __fcn_i.
So while in the source code, two overloaded functions share a name, in compiled code, the names are actually unique.
There is no standardization on how names should be mangled, so different compilers will produce different mangled names.

*/





// Related page: https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/

