#include "add.h" // for BasicMath::add()

#include <iostream>


void print() // this print() lives in the global namespace
{
	std::cout << " there\n";
}

namespace Foo // Foo is defined in the global scope
{
    int g_x {}; // // g_x is now inside the Foo namespace, but is still a global variable

	void print() // this print() lives in the Foo namespace
	{
		std::cout << "Hello";
	}

	void printHelloThere()
	{
		print();   // calls print() in Foo namespace
		::print(); // calls print() in global namespace
	}
}




int main()
{
    std::cout << "BasicMath namespace: " << BasicMath::add(4, 3) << '\n'; //  use the scope resolution operator (::)

    Foo::printHelloThere();
    Foo::g_x = 5; // // global variables can be seen and used everywhere in the file
    std::cout << "g_x value: "<<Foo::g_x << '\n';

    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
