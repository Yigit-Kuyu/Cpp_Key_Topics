#include <iostream>
#include <typeinfo>
/*
We can use assignment with pointers in two different ways:

To change what the pointer is pointing at (by assigning the pointer a new address)
To change the value being pointed at (by assigning the dereferenced pointer a new value)

*/


/*

When we use a pointer without a dereference (ptr), we are accessing the address held by the pointer.
Modifying this (ptr = &y) changes what the pointer is pointing at.

When we dereference a pointer (*ptr), we are accessing the object being pointed at.
Modifying this (*ptr = 6;) changes the value of the object being pointed at.

*/


int main()
{
    int x{ 5 };
    int* ptr{ &x }; // ptr initialized to point at x

    std::cout << *ptr << '\n'; // print the value at the address being pointed to (x's address)

    int y{ 6 };
    int* p{}; // a null pointer
    p = &y; // change ptr to point at y

    std::cout << "pointed to y: " << *p << '\n'; // print the value at the address being pointed to (y's address)

    *ptr = 60; // The object at the address held by ptr (x) assigned value 6 (note that ptr is dereferenced here)

    std::cout << "ptr: " << *ptr << '\n'; // print the value at the address that ptr is holding (x's address)
    std::cout << "changed x: "   << x << '\n';     // x is changed since ptr is changed.


    // It’s worth noting that the address-of operator (&) doesn’t return the address of its operand as a literal.
    // Instead, it returns a pointer containing the address of the operand.
    // So, the address-of operator returns a pointer:

    int x1{ 4 };
	std::cout << "return type of int adress x1: "<< typeid(&x1).name() << '\n'; // prints “pi” (pointer to int).


    // Pointers behave much like references:
    int xx{ 5 };
    int& ref { xx };  // get a reference to x
    int* ptr1 { &xx }; // get a pointer to x

    std::cout << "Pointers behave much like references: " << xx << " ";
    std::cout << "Pointers behave much like references: " << ref << " " ;  // use the reference to print x's value (5)
    std::cout << "Pointers behave much like references: " << *ptr1 << '\n'; // use the pointer to print x's value (5)

    ref = 6; // use the reference to change the value of x
    std::cout << "Pointers behave much like references: " << xx << " ";
    std::cout << "Pointers behave much like references: " << ref << " ";  // use the reference to print x's value (6)
    std::cout << "Pointers behave much like references: " << *ptr1 << '\n'; // use the pointer to print x's value (6)

    *ptr = 7; // use the pointer to change the value of x
    std::cout << "Pointers behave much like references: " << xx << " ";
    std::cout << "Pointers behave much like references: " << ref << " ";  // use the reference to print x's value (7)
    std::cout << "Pointers behave much like references: " << *ptr1 << '\n'; // use the pointer to print x's value (7)

     /*
     The primary difference is that with pointers, we need to explicitly get the address to point at, and we have to explicitly
     dereference the pointer to get the value. With references, the address-of and dereference happens implicitly.
     The terms "explicit" and "implicit" in this context refer to whether you, the programmer, need to manually write code
     to perform certain actions (explicit), or whether the compiler automatically does it for you (implicit).

     There are some other differences between pointers and references worth mentioning:

    -References must be initialized, pointers are not required to be initialized (but should be).
    -References are not objects, pointers are.
    -References can not be reseated (changed to reference something else), pointers can change what they are pointing at.
    -References are “safe”, pointers are inherently dangerous (we’ll also discuss this in the next lesson)

     */

    int xxx{ 50 };
    const int* ptrrr{ &xxx }; // ptr initialized to point at x

    // *ptrrr=80; // error; you cannot change the const value
    xxx=80;

    std::cout << "after xxx is changed: "<< *ptrrr << '\n'; // const pointer is indirecly modified.

     int yy{6};
     ptrrr = &yy; // no error: you can change the pointed address of const value


    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
