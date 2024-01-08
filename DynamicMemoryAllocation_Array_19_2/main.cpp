#include <cstddef>
#include <iostream>

/*

In these lessons, we’ll be dynamically allocating C-style arrays, which is the most common type of dynamically allocated array.

While you can dynamically allocate a std::array, you’re usually better off using a non-dynamically allocated std::vector in this case.

*/


/*

Resizing arrays

Dynamically allocating an array allows you to set the array length at the time of allocation.
However, C++ does not provide a built-in way to resize an array that has already been allocated.
It is possible to work around this limitation by dynamically allocating a new array, copying the elements over, and deleting the old array.
However, this is error prone, especially when the element type is a class (which have special rules governing how they are created).

Consequently, we recommend avoiding doing this yourself. Use std::vector instead.

*/



int main()
{
    std::cout << "Enter a positive integer: ";
    std::size_t length{}; // The length of dynamically allocated arrays has type std::size_t
    std::cin >> length;

    // Initialize a dynamically allocated array to 0.
    int* array{ new int[length]{} }; // use array new.  Note that length does not need to be constant!

    std::cout << "I just allocated an array of integers of length " << length << '\n';

    array[0] = 5; // set element 0 to value 5

    delete[] array; // use array delete to deallocate array

    // we don't need to set array to nullptr/0 here because it's going out of scope immediately after this anyway

    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays/


