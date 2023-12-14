#include <iostream>

void print(int x)
{
	std::cout << x << '\n';
}

int main()
{

//Whenever you see C++ syntax (excluding the preprocessor) that makes use of angled brackets (<>),
//the thing between the angled brackets will most likely be a type.

    double x=5.5;

	// static_cast<new_type>(expression)
	print( static_cast<int>(x) ); // explicitly convert double value 5.5 to an int


	char ch{ 97 }; // 97 is ASCII code for 'a'
	// print value of variable ch as an int
    std::cout << ch << " has value " << static_cast<int>(ch) << '\n';

	return 0;
}


// related page: https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
