#include <iostream>
#include <vector>

// The length and indices of std::vector have type size_type.
// size_type is almost always an alias for std::size_t which is unsigned.

// Getting the length of a std::vector using the size() member function or std::size()
// returns size_type (alias is size_t) that is unsigned.

// Sign conversions are considered to be narrowing conversions because a signed or unsigned type cannot hold all the values contained
// in the range of the opposing type. When such a conversion is attempted at runtime,
// the compiler will issue an error in contexts where narrowing conversions are disallowed (such as in list initialization),
// and may or may not issue a warning in other contexts where such a conversion is required.

void foo(unsigned int)
{
}

int main()
{
    int s { 5 };

    // signed/unsigned conversion warning or error:
    //unsigned int u { s }; // compile error: list initialization disallows narrowing conversion
    foo(s); // possible warning: copy initialization allows narrowing conversion

    std::vector prime1 { 2, 3, 5, 7, 11, 18, 22 };
    std::cout << "length1: " << prime1.size() << '\n'; // returns length as type `size_type` (alias for `std::size_t`)

    std::vector prime2 { 2, 3, 5, 7, 11 };
    int length { static_cast<int>(prime2.size()) }; // To avoid conversation warning/error, static_cast return value to int
    std::cout << "length2: " << length << '\n';

    // Accessing array elements using operator[] does no bounds checking:
    std::cout << "Accessing element with [] operator: " << prime1[3] << '\n';  // print the value of element with index 3 (7)
    std::cout << "Accessing element with [] operator: " << prime1[10]<< '\n';; // invalid index (undefined behavior, output: 1041)

    // Accessing array elements using the at() member function does runtime bounds checking:
    std::cout << "Accessing element with at operator: " << prime1.at(3)<< '\n';; // print the value of element with index 3
     std::cout << "Accessing element with at operator: " << prime1.at(10)<< '\n';; // invalid index (throws exception)


     // Note: at() is slower (but safer) than operator[]. Despite being less safe, operator[] is typically used over at().


    return 0;
}


