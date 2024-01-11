#include <iostream>

/*

Rules of operator overloading:
-Almost any existing operator in C++ can be overloaded.
The exceptions are: conditional (?:), sizeof, scope (::), member selector (.), pointer member selector (.*), typeid, and the casting operators.
-You can only overload the operators that exist. You can not create new operators or rename existing operators.
-All operators keep their default precedence and associativity.

*/


class Cents
{
private:
	int m_cents {};

public:
	Cents(int cents) : m_cents{ cents } { }

	// add Cents + Cents using a friend function
	friend Cents operator+(const Cents& c1, const Cents& c2); // Since we use friend function, we dont need function prototeype

    // add Cents + int using a friend function
	friend Cents operator+(const Cents& c1, int value);

	// add int + Cents using a friend function
	friend Cents operator+(int value, const Cents& c1);


	int getCents() const { return m_cents; } // getter
};

// note: this function is not a member function!
Cents operator+(const Cents& c1, const Cents& c2)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return c1.m_cents + c2.m_cents;
}


// note: this function is not a member function!
Cents operator+(const Cents& c1, int value)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return c1.m_cents + value;
}

// note: this function is not a member function!
Cents operator+(int value, const Cents& c1)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return c1.m_cents + value;
}


int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 8 };
	Cents centsSum{ cents1 + cents2 }; // Call Cents operator+(.....)--> for cents1 + cents2, operator is looking function return type (in our case, Cents) and function parameter type (in our case, Cents, Cents)
	std::cout << "I have " << centsSum.getCents() << " cents.\n";

	// When the operands have different types, x + y does not call the same function as y + x.
	// We actually need to write two functions -- one for each case:
    Cents c1{ Cents{ 4 } + 6 }; // function parameters: Cents, int -->c1.m_cents=10
	Cents c2{ 6 + Cents{ 4 } };  // function parameters: int, Cents -->c2.m_cents=10

	std::cout << "I have " << c1.getCents() << " cents.\n";
	std::cout << "I have " << c2.getCents() << " cents.\n";

	return 0;

}




// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-operator-overloading/
//               https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions/
