#include <array>  // for std::array
#include <vector> // for std::vector
#include <iostream>

/*
We mentioned that arrays fall into two categories:

    -Fixed-size arrays (also called fixed-length arrays) require that the length of the array be known at the point of instantiation,
    and that length cannot be changed afterward. C-style arrays and std::array are both fixed-size arrays.
    -Dynamic arrays can be resized at runtime. std::vector is a dynamic array.

*/


/*

Why not use dynamic arrays for everything?
    -std::vector is slightly less performant than the fixed-size arrays. In most cases you probably won’t notice the difference.
    -std::vector only supports constexpr in very limited contexts.

Note: In modern C++, it is really this latter point that’s significant. Constexpr arrays offer the ability to write code that is more robust,
and can also be optimized more highly by the compiler.
The support for constexpr is the key reason to use std::array. If your std::array is not constexpr, consider using a std::vector instead.

*/


int main()
{
    std::array<int, 5> a {};  // a std::array of 5 ints

    std::vector<int> b(5);    // a std::vector of 5 ints (for comparison)

    // #############   Adjust length of the array:
    int len{3};
    //std::array<int, len> c {}; // Error: The length of a std::array must be a constant expression
    std::vector<int> d(len);    // No error for vector (for comparison)


    constexpr int len1 {8};
    std::array<int, len1> c1 {}; // Ok, no error for array
    std::vector<int> d1(len1); // Ok, no error for vector for comparison)


    // ########### Initialization:
    std::array<int, 5> prime1 { 2, 3, 5, 7, 11 };         // list initialization using braced list (preferred)
    std::array<int, 6> fibonnaci = { 0, 1, 1, 2, 3, 5 }; // copy-list initialization using braced list
    std::array<int, 5> b1{}; // Members value initialized (int elements are zero initialized) (preferred)

    // ############# Type deduction:
    constexpr std::array a1 { 9, 7, 5, 3, 1 }; // The type is deduced to std::array<int, 5>
    constexpr std::array a2 { 9.7, 7.31 };     // The type is deduced to std::array<double, 2>


    // ############# Accessing array elements using operator[]:
    constexpr std::array<int, 5> prime{ 2, 3, 5, 7, 11 };
    std::cout << prime[3]; // print the value of element with index 3 (7)
    std::cout << prime[9]; // invalid index (undefined behavior)



    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/


