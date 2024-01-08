#include <iostream>


// A pointer is a variable that holds the address of another variable.
// Function pointers are similar, except that instead of pointing to variables, they point to functions.


// fcnPtr is a pointer to a function that takes no arguments and returns an integer
// int (*fcnPtr)(); // The syntax for creating a non-const function pointer
// int (*const fcnPtr)(); // The syntax for creating a const function pointer


int foo()
{
    return 5;
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
    int (*fcnPtr)(){ &foo };    // OK: fcnPtr points to function foo
    //int (*fcnPtr2)(){ &goo };  // Error: wrong -- return types don't match!
    double (*fcnPtr4)(){ &goo }; // OK
    //fcnPtr = &goo; // Error:  wrong -- return types don't match!
    fcnPtr4 = &goo; // OK
    //fcnPtr=&hoo; // Error: wrong -- fcnPtr1 has no parameters, but hoo() does

    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/function-pointers/
