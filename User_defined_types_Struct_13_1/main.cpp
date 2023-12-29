#include "Fraction.h" // include our Fraction definition in this code file



// Consider the case of a type alias (Type aliases_Using_10_7), which allows us to define a new name for an existing type.
// Rather than creating type alias for each variable, C++ allow us to create entirely new, custom types
// for use in our programs! Such types are often called user-defined types.


// User-defined types are typically fully defined in header files, and then #included
// into any code file that requires that type definition (a forward declaration is not sufficient).


int main()
{
	Fraction f{ 3, 4 }; // this actually creates a Fraction object named f

	return 0;
}





// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/
