#include <iostream>
#include <cstddef> // for NULL


// I close this function ( void print(int x) ),
// because if open, "print(x);" in the main, does not know, which function that it will go ( void print(int x) or void print(int& reff)  )

/*
void print(int x) // this function accepts an integer
{
	std::cout << "print(int): " << x << '\n';
}
*/




void print(int* ptr) // this function accepts an integer pointer
{
	std::cout << "print(int*): " << (ptr ? "non-null\n" : "null\n") << '\n';
}




void print(int& reff) // this function accepts an integer pointer
{
	std::cout << "print(int&): " << (reff==1 ? "ref is one" : "other") << std::endl;
}




int main()
{
	int x{ 0 };
	int* ptr{ &x };

	print(ptr);  // always calls print(int*)  (good)
	print(x);   // always calls print(int&)  (good)

	print(0);    // (not good but no error), 0 behaves as null pointer literal, and call print(int*)
    // if you want to use 0 literal,
    // activate void print(int x) function ( of course, comment out void print(int& reff) )
    // because the compiler will prefer print(int) over print(int*).


	print(NULL);
	// if you activate void print(int x) ( of course, comment out void print(int& reff) ),
	// the error "call of overloaded ‘print(NULL)’ is ambiguous" will raise.

	// this statement could do any of the following:
	// call print(int)
	// call print(int*)
	// result in an ambiguous function call compilation error (gcc and Clang do this)

	print(nullptr); // always calls print(int*)


	// As a result, you should pay attention in using 0 literal and NULL. For safety, use nullptr.


	return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2/
