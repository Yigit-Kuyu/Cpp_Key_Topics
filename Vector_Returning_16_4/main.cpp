#include <iostream>
#include <vector>

// When we need to pass a std::vector to a function, we pass it by (const) reference so that we do not make a copy.
// Therefore, you will probably be surprised to find that it is okay to return a std::vector by value.

// Because return by value returns an rvalue, if the returned type supports move semantics,
// then the returned value can be moved instead of copied into the destination object!
// This makes return by value extremely inexpensive for these types!

// Move semantics means the class will transfer ownership of the object rather than making a copy.


/*
Move semantics will be used instead of copy semantics when all of the following are true:

-The type supports move semantics.
-We are initializing or assigning to an object using an rvalue object of the same type.

Here’s the sad news: not that many types support move semantics. However, std::vector and std::string both do!

*/



int main()
{
    // When arr2 is initialized with arr1, the copy constructor of std::vector is called, which copies arr1 into arr2
    std::vector arr1 { 1, 2, 3, 4, 5 }; // copies { 1, 2, 3, 4, 5 } into arr1
    std::vector arr2 { arr1 };          // copies arr1 into arr2 (arr1 and arr2 to live on independently)


    // When initializing or assigning a value to an object, copies the value (from another object),
    // we say the object is using copy semantics.

    arr1[0] = 6; // We can continue to use arr1
    arr2[0] = 7; // and we can continue to use arr2

    std::cout << arr1[0] << arr2[0] << '\n';

    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdvector-and-an-introduction-to-move-semantics/
