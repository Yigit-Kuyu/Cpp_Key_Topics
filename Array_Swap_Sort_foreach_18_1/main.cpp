#include <algorithm> // for std::sort
#include <iostream>
#include <iterator> // for std::size

void doubleNumber(int& i)
{
    i *= 2;
}


int main()
{
	//int array[]{ 30, 50, 20, 10, 40 };
	std::array arr{ 6, 2, 3, 4 };

	std::sort(std::begin(arr), std::end(arr)); // sorts in ascending order

	for (int i{ 0 }; i < static_cast<int>(std::size(arr)); ++i)
		std::cout << arr[i] << ' ';

	std::cout << '\n';


	int x{ 2 };
    int y{ 4 };
    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    std::swap(x, y); // swap the values of x and y
    std::cout << "After swap:  x = " << x << ", y = " << y << '\n';




    std::for_each(arr.begin(), arr.end(), doubleNumber); // Applies a custom function to every element.
    for (int i : arr)
    {
        std::cout << i << ' ';
    }


	return 0;
}

// The related page: https://www.learncpp.com/cpp-tutorial/sorting-an-array-using-selection-sort/
//                   https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/
