#include <array>
#include <iostream>


/*
An object of type std::array can be passed to a function just like any other object.
That means if we pass a std::array by value, an expensive copy will be made.
Therefore, we typically pass std::array by (const) reference to avoid such copies.
For similar implementation to vector, see Vector_Passing_16_4

*/

// Note that the type of the non-type template parameter for std::array should be std::size_t, not int!
template <typename T, std::size_t N>
void passByRef_withTemplate(const std::array<T, N>& arr)
{
    std::cout << arr[0] << '\n';
}


template <std::size_t N> // note: only the length has been templated here
void passByRef_withLenTemplate(const std::array<int, N>& arr) // we've defined the element type as int
{
    std::cout << arr[3] << '\n';

    // If "arr" is a 2-element array:
    // std::array arr1{9, 7}; //  std::array<int, 2>
    // passByRef_withTemplate(arr1); // size_t N = 2
    // the index 3 will be out of bounds, this will issue undefined behavior.

    // One solution is to use std::get() (which does compile-time bounds checking) instead of operator[] (which does no bounds checking):
    std::cout << std::get<3>(arr) << '\n'; // checks that index 3 is valid at compile-time

    // An alternative solution is to use static_assert to validate a precondition on the array length ourselves:
    // Precondition: array length must be greater than 3 so element 3 exists
    static_assert (N > 3);
    // We can assume the array length is greater than 3 beyond this point
    std::cout << arr[3] << '\n';
}




void passByRef(const std::array<int, 5>& arr) // we must explicitly specify <int, 5> here
{
    std::cout << arr[0] << '\n';

}

int main()
{
    std::array arr{ 9, 7, 5, 3, 1 }; // CTAD (type deduction) deduces type std::array<int, 5>
    passByRef(arr);


    std::array arr1{ 9, 7, 5, 3, 1 }; // use CTAD to infer std::array<int, 5>
    passByRef_withTemplate(arr1);  // ok: compiler will instantiate passByRef(const std::array<int, 5>& arr)
    std::array arr2{ 1, 2, 3, 4, 5, 6 }; // use CTAD to infer std::array<int, 6>
    passByRef_withTemplate(arr2); // ok: compiler will instantiate passByRef(const std::array<int, 6>& arr)
    std::array arr3{ 1.2, 3.4, 5.6, 7.8, 9.9 }; // use CTAD to infer std::array<double, 5>
    passByRef_withTemplate(arr3); // ok: compiler will instantiate passByRef(const std::array<double, 5>& arr



    passByRef_withLenTemplate(arr1);  // ok: compiler will instantiate passByRef(const std::array<int, 5>& arr)
    passByRef_withLenTemplate(arr2); // ok: compiler will instantiate passByRef(const std::array<int, 6>& arr)
    //passByRef_withLenTemplate(arr3); // error: compiler can't find matching function


    return 0;
}






// Related page: https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/
