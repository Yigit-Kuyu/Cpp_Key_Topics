#include <iostream>

/*
The & symbol tends to cause confusion because it has different meanings depending on context:

When following a type name, & denotes an lvalue reference: int& ref.
When used in a unary context in an expression, & is the address-of operator: std::cout << &x.
When used in a binary context in an expression, & is the Bitwise AND operator: std::cout << x & y.
*/


// A pointer is an object that holds a memory address (typically of another variable) as its value.
// This allows us to store the address of some other object to use later.

// int* ptr1 {x};
// This is where pointers get their name from -- ptr is holding the address of x, so we say that ptr is “pointing to” x.

#include <iostream>

int main()
{
    // Note that the asterisk symbol is part of the declaration syntax for pointers, not a use of the dereference operator.
    int xx{ 5 };
    int* ptr1;        // an uninitialized pointer (holds a garbage address)
    int* ptr2{};     // a null pointer (we'll discuss these in the next lesson)
    int* ptr3{ &xx }; // a pointer initialized with the address of variable x

    std::cout << "pointer value: " << *ptr3 << '\n'; // use dereference operator to print the value at the address that ptr is holding (which is x's address)

    int x1 { 5 };    // normal variable
    int& reff { x1 }; // a reference to an integer (bound to x1)
    int* ptr;       // a pointer to an integer


   // Much like the type of a reference has to match the type of object being referred to,
   // the type of the pointer has to match the type of the object being pointed to:

    int i{ 5 };
    double d{ 7.0 };

    int* iPtr{ &i };     // ok: a pointer to an int can point to an int object
    //int* iPtr2 { &d };   // error: a pointer to an int can't point to a double object
    double* dPtr{ &d };  // ok: a pointer to a double can point to a double object
    //double* dPtr2{ &i }; // error: a pointer to a double can't point to an int object



    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x

    // The address-of operator (&) and dereference operator (*) work as opposites:
    // "address-of" gets the address of an object, and "dereference" gets the object at an address.

    std::cout << "address x: " << &x << '\n'; // print the memory address of variable x

    std::cout << "value x: " << *(&x) << '\n'; // dereference operator, print the value at the memory address of variable x (parentheses not required, but make it easier to read)

    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
