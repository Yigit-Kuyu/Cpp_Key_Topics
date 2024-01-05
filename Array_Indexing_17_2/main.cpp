#include <array>
#include <iostream>


// The length of a std::array has type std::size_t (same as vector.size(), see Vector_Unsigned_16_6)


int main()
{

    // Unlike std::string and std::string_view, which have both a length() and a size() member function (that do the same thing),
    // std::array (and most other container types in C++) only have size().

    constexpr std::array arr{ 9, 7, 5, 3, 1 };
    // Both are for same purpose:
    std::cout << "length: " << arr.size(); // C++17, returns length as type `size_type` (alias for `std::size_t`)
    std::cout << "length: " << std::size(arr); // C++17, returns length as type `size_type` (alias for `std::size_t`)

    // Just like std::vector, std::array also has an at() member function.
    // operator [] and at()  expect the index to be of type size_type (std::size_t).
    // operator[] does no bounds checking by definition,
    // and the at() member function only does runtime bounds checking. (Same as vectors, see Vector_length_16_3).
    // To get compile-time bounds checking when we have a constexpr index, we can use the std::get() function template:

    constexpr std::array prime{ 2, 3, 5, 7, 11 };

    std::cout << std::get<3>(prime); // print the value of element with index 3
    //std::cout << std::get<9>(prime); // Error: invalid index (compile error)


    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing/







// Related page: https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing/#google_vignette
