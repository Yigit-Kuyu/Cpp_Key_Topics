#include <array>
#include <iostream>

/*
Syntax aside, passing a std::array to a function is conceptually simple -- pass it by (const) reference.
But what if we have a function that needs to return a std::array? Things are a little more complicated.
Unlike std::vector, std::array is not move-capable, so returning a std::array by value will make a copy of the array.
For move semantics property in vectors: see Vector_Returning_16_4

So, there are three options to return:
      - return by value: returning directly std::array if it is not expensive
      - return via out parameter: passing in the std::array by non-const reference (or by address), and the function can then modify this array.
      - return std::vector instead: see Vector_Returning_16_4

*/


// return by value:
template <typename T, std::size_t N>
std::array<T, N> inputArray_byValue(std::array<T, N>& arr)
{

	arr[2]=1;


	return arr;
}


// return via out parameter:
template <typename T, std::size_t N>
void inputArray_byParameter(std::array<T, N>& arr2)
{

	arr2[2]=5;

}



int main()
{
	std::array<int, 5>yck{};
	std::array<int, 5> arr=inputArray_byValue(yck);

	std::cout << " return-by-value of element 2 is " << arr[2] << '\n';

	inputArray_byParameter(yck);

	std::cout << " return-via-out-parameter of element 2 is " << yck[2] << '\n';

	return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdarray/
