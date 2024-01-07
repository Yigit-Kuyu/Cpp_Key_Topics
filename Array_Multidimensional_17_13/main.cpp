#include <array>
#include <iostream>

template <typename T, std::size_t Row, std::size_t Col>
void printArray(std::array<std::array<T, Col>, Row> &arr)
{
    for (const auto& arow: arr)   // get each array row
    {
        for (const auto& e: arow) // get each element of the row
            std::cout << e << ' ';

        std::cout << '\n';
    }
}

template <typename T, std::size_t Row, std::size_t Col>
using Array2d_everycombination = std::array<std::array<T, Col>, Row>; //  alias for every combination of element type and dimensions we want to use

template <typename T, std::size_t Row, std::size_t Col> // // When using Array2d_everycombination  as a function parameter, we need to respecify the template parameters
void printArray_withAlias(Array2d_everycombination<T, Row, Col> &arr)  //  Pay attention to definition: not Array2d_everycombination<T, Col>, Row> &arr
{
    for (const auto& arow: arr)   // get each array row
    {
        for (const auto& e: arow) // get each element of the row
            std::cout << e << ' ';

        std::cout << '\n';
    }
}


int main()
{

    // A two-dimensional std::array:
    std::array<std::array<int, 4>, 3>  arr {{  // 3X4 array
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
        }};

    std::cout << arr[1][2]<<'\n'; // print the element in row 1, column 2
    std::cout << '\n';

    std::cout <<"arr: " <<'\n';
    printArray(arr); // pass by reference
    std::cout << '\n';



    // Pay attention to definition: not Array2d_everycombination<int, 5>, 3> arr2
    Array2d_everycombination<int, 5, 3> arr2 // 5X3 using type alias
     {{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15}

        }};

    std::cout <<"arr2: " <<'\n';
    printArray_withAlias(arr2); // pass by reference
    std::cout << '\n';




    using Array2dint34 = std::array<std::array<int, 4>, 3>; // type alias for only 3X4 array
    Array2dint34  arr3 {{  // 3X4 array
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
        }};
    std::cout <<"arr3: " <<'\n';
    printArray(arr3); // pass by reference
    std::cout << '\n';


    return 0;
}

// Related page: https://www.learncpp.com/cpp-tutorial/multidimensional-stdarray/
