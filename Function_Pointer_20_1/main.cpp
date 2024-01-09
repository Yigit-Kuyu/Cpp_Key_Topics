#include <iostream>


// A pointer is a variable that holds the address of another variable.
// Function pointers are similar, except that instead of pointing to variables, they point to functions.


// fcnPtr is a pointer to a function that takes no arguments and returns an integer
// int (*fcnPtr)(); // The syntax for creating a non-const function pointer
// int (*const fcnPtr)(); // The syntax for creating a const function pointer


// One of the most useful things to do with function pointers is pass a function as an argument to another function.
// Functions used as arguments to another function are sometimes called "callback functions".

int foo(int x)
{
    return x;
}

double goo()
{
    return 6;
}


int hoo(int x)
{
    return 10;

}


int main()
{
    int (*fcnPtr)(int){ &foo };    // OK: fcnPtr points to function foo
    //int (*fcnPtr2)(){ &goo };  // Error: wrong -- return types don't match (int!=double)
    double (*fcnPtr3)(){ &goo }; // OK
    //fcnPtr = &goo; // Error:  wrong -- return types don't match!
    //fcnPtr3=&hoo; // Error: wrong -- fcnPtr3has no parameters, but hoo() does

    int x{};
    if (fcnPtr) // make sure fcnPtr isn't a null pointer
       x =fcnPtr(5); // otherwise this will lead to undefined behavior

    std::cout<< "x is " << x << std::endl;

    auto fcnPtr7{ &foo }; //  the auto keyword can infer the type of a function pointer.
	std::cout << fcnPtr7(7) << '\n';

    // Note: We recommend using std::function rather than function pointers.

    return 0;



}


// Related page: https://www.learncpp.com/cpp-tutorial/function-pointers/
