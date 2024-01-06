#include <iostream>
#include <array>  // For array 'arr', C-style arrays does not need <array> headder
#include <iterator> // for std::size


// We’ve covered std::vector and std::array, we’ll complete our coverage of arrays by covering the last array type: C-style arrays.
// C-style arrays were inherited from the C language, and are built-in to the core language of C++.
// They are the only array type natively supported by the language (unlike the rest of the array types, which are standard library container classes).


//  The length of the C-style array, which is an integral value of type std::size_t (as same as array and vector).
// The main drawback is since C-style arrays were inherited from the C language, C doesn’t have references,
// so using pass by reference to avoid making a copy of function arguments wasn’t an option.

// pass by address:
// void printElementZero(const int* arr)  // not prefered, because  declaring the function parameter as int* arr is that it’s not obvious
                                         //  that arr is supposed to be a pointer to an array of values rather than a pointer to a single integer.
void printElementZero(const int arr[]) // prefered, treated the same as const int*
{
    std::cout << "pass by addrees:: " <<arr[0]<<'\n';
    //std::cout << std::size(arr) << '\n'; // error: std::size() won't work on a pointer
}


int main()
{
    // Decleration:
    int testScore[30] {};      // Defines a C-style array named testScore that contains 30 value-initialized int elements (no include required)
    std::array<int, 30> arr{}; // For comparison, here's a std::array of 30 value-initialized int elements (requires #including <array>)
    // Note: When declaring an array (e.g. int arr[5]), the use of [] is part of the declaration syntax,
    //       not an invocation of the subscript operator operator[].


    // Initialization:
    int fibonnaci[6] = { 0, 1, 1, 2, 3, 5 }; // copy-list initialization using braced list
    int prime[5] { 2, 3, 5, 7, 11 };         // list initialization using braced list (preferred)
    const int prime1[] { 2, 3, 5, 7, 11 };  // prime2 deduced by compiler to have length 5 (we can omit the length in the array definition)
    // int a[4] { 1, 2, 3, 4, 5 }; // error: too many initializers
    int b[4] { 1, 2 };          // no error:: arr[2] and arr[3] are value initialized
    // auto squares[5] { 1, 4, 9, 16, 25 }; // error: can't use type deduction on C-style arrays


    // Assignment:
    int arr1[5]; // define an array of 5 int values
    arr1[1] = 7; // use subscript operator to index array element 1
    std::cout << arr1[1] << '\n'; // prints 7


    // const/constexpr array:
    /*
    Just like std::array, C-style arrays can be const or constexpr.
    Just like other const variables, const arrays must be initialized, and the value of the elements cannot be changed afterward.
    */

    const int prime2[5] { 2, 3, 5, 7, 11 }; // an array of const int
    // prime2[0] = 17; // error: can't change const int


    // Length of array:
    std::cout << std::size(prime2) << '\n';  // C++17, returns unsigned integral value 5


    // C doesn’t have references, C-style array  has no references, we use pointers.
    // The array will be implicitly converted into a pointer to the element type, initialized with the address of the first element (with index 0).
    // Colloquially, this is called array decay.
    // array decay:
    auto ptr{ prime }; // evaluation causes arr to decay, type deduction should deduce type int*
    std::cout << std::boolalpha << (typeid(ptr) == typeid(int*)) << '\n'; // Prints true if the type of ptr is int*
    std::cout << std::boolalpha << (&prime[0] == ptr) << '\n'; // the pointer holds the address of the first element of the array
    std::cout << ptr[2] <<'\n';    // subscript ptr to get element 2

    //  C-style array is passed by address:
    const int squares[] { 1, 4, 9, 25, 36, 49, 64, 81 };
    printElementZero(prime2);   // prime2 decays to an const int* pointer
    printElementZero(squares); // squares decays to an const int* pointer



    return 0;
}


// Note: We recommend avoiding  C-style arrays as much as possible.




// Related page:: https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
