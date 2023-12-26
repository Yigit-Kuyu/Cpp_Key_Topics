#include <iostream>

// write your add function template here

template<typename T>
T add(T x, T y)
{
      return x+y;
}

template<typename T1>
T1 mult(T1 x, int y)
{
    return x*y;
}

template<typename T2, typename T3>
auto sub(T2 x, T3 y)
{
      return x-y;

}



int main()
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';
    std::cout << '\n';

    std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';
	std::cout << '\n';

    std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/
