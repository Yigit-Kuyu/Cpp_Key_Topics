#include <iostream>

using namespace std;

int main()
{


    //##### Initializing 2D arrays:
    int array1[3][5]
{
  { 1, 2, 3, 4, 5 },     // row 0
  { 6, 7, 8, 9, 10 },    // row 1
  { 11, 12, 13, 14, 15 } // row 2
};

    int array2[3][5] // missing initializers will be value-initialized
{
  { 1, 2 },          // row 0 = 1, 2, 0, 0, 0
  { 6, 7, 8 },       // row 1 = 6, 7, 8, 0, 0
  { 11, 12, 13, 14 } // row 2 = 11, 12, 13, 14, 0
};

    int array3[][5]  // can omit (only) the leftmost length specification
{
  { 1, 2, 3, 4, 5 },
  { 6, 7, 8, 9, 10 },
  { 11, 12, 13, 14, 15 }
};


    //####### 1D arrays and loop:
    std::cout << "1D arrays: " << '\n';

    int arr[] { 1, 2, 3, 4, 5 }; // 1D array

    // for-loop with index (1D array)
    for (std::size_t i{0}; i < std::size(arr); ++i)
        std::cout << arr[i] << ' ';
         std::cout << '\n';

    // range-based for-loop (1D array)
    for (auto e: arr)
        std::cout << e << ' ';

    std::cout << '\n';

    //########## 2D arrays and loop: (we need two loops: one to select the row, and another to select the column)
    std::cout << "2D arrays: " << '\n';

    // double for-loop with indices
    for (std::size_t row{0}; row < std::size(array1); ++row) // std::size(arr) returns the number of rows
    {
        for (std::size_t col{0}; col < std::size(array1[0]); ++col) // std::size(arr[0]) returns the number of columns
            std::cout << array1[row][col] << ' ';

        std::cout << '\n';
    }

    // double range-based for-loop
    for (const auto& arow: array1)   // get each array row
    {
        for (const auto& e: arow) // get each element of the row
            std::cout << e << ' ';

        std::cout << '\n';
    }




    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/multidimensional-c-style-arrays/
