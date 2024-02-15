#include <iostream>


// Without virtual functions, base class pointers and references to a derived class
// will only have access to base class member variables and versions of functions.

// A virtual function is a special type of function that resolves
// to the most-derived version of the function (called an override) that exists between the base and derived class.

// To be considered an override, the derived class function must have the same signature and return type as the virtual base class function.

//  A function that is intended to be an override should use the override specifier to ensure that it is actually an override.

class Base
{
public:
	virtual void print() const { std::cout << "Base";  }
};

class Derived : public Base
{
public:
	void print() const override { std::cout << "Derived"; } // "override" is optional
};

int main()
{
	Derived d{};
	Base& b{ d }; // Base class reference to derived class
	Base* b1=&d; // / Base class pointer to derived class

	std::cout << "b is a ";

	// will call Derived::print(), because b is pointing to a Derived class object, Base::print() is a virtual function.
	b.print(); // output: Derived
	b1->print(); // output: Derived

	std::cout << '\n';

	return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/printing-inherited-classes-using-operator/
