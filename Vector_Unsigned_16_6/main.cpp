#include <iostream>
#include <vector>

template <typename T>
void printReverse(const std::vector<T>& arr)
{
    //for (std::size_t index{ arr.size() - 1 }; index >= 0; --index) // index is unsigned (warning: segmentation fault)
    // for (int index{ static_cast<int>(arr.size()) - 1}; index >= 0; --index) // Ok, index is signed, but using static_cast is particularly hard to read.
    for (std::size_t index { 0 }; index < arr.size(); ++index) // prefer size_t for array indexing
    {
        std::cout << arr[index] << ' ';
    }

    std::cout << '\n';
}

int main()
{
    std::vector arr{ 4, 6, 2, 1, 9 };

    printReverse(arr);

    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
