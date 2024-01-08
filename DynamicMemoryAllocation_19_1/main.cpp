#include <iostream>

/*
Static memory allocation:
    happens for static and global variables. Memory for these types of variables is allocated once when your program is run
    and persists throughout the life of your program.
Automatic memory allocation:
    happens for function parameters and local variables. Memory for these types of variables is allocated
    when the relevant block is entered, and freed when the block is exited, as many times as necessary.
Dynamic memory allocation:
    is the topic of this article.

*/

/*
Both static and automatic allocation have two things in common:

-The size of the variable / array must be known at compile time.
-Memory allocation and deallocation happens automatically (when the variable is instantiated / destroyed).

Most of the time, this is just fine.  However, you will come across situations where one or both of these constraints cause problems,
usually when dealing with external (user or file) input.

*/



int main()
{
    // Dynamically allocating single variables:
    int* ptr{ new int }; // dynamically allocate an integer
    int* ptr1{ new int (5) }; // use direct initialization
    int* ptr2{ new int { 6 } }; // use uniform initialization

    if (!ptr) // // If ptr isn't already allocated, allocate it
      ptr = new int;

    *ptr = 7; // put a value in that memory location

     std::cout << *ptr << '\n';

    delete ptr; // return the memory to the operating system.


    // Memory leaks happen when your program loses the address of some bit of dynamically allocated memory
    // before giving it back to the operating system.
    // When this happens, your program can’t delete the dynamically allocated memory, because it no longer knows where it is.
    int value = 5;
    int* ptr3{ new int{} }; // allocate memory
    ptr3 = &value; // old address lost, memory leak results



    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/


