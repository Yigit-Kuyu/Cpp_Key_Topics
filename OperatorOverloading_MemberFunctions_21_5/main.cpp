#include <iostream>



/*
Note: Not everything can be overloaded as a friend function (for the usage of friend function see OperatorOverloading_21_1):
The assignment (=), subscript ([]), function call (()), and member selection (->) operators must be overloaded as member functions.


*/

class Cents
{
private:
    int m_cents {};

public:
    Cents(int cents)
        : m_cents { cents } { }

    // Overload Cents + int
    Cents operator+(int value) const;

    int getCents() const { return m_cents; }
};

// note: this function is a member function!
// the cents parameter in the friend version is now the implicit *this parameter
Cents Cents::operator+ (int value) const
{
    return Cents { m_cents + value };
}

int main()
{
	const Cents cents1 { 6 };
	const Cents cents2 { cents1 + 2 }; // In the member function version, the expression cents1 + 2 becomes function call cents1.operator+(2).
	std::cout << "I have " << cents2.getCents() << " cents.\n";

	return 0;
}

// Related page: https://www.learncpp.com/cpp-tutorial/overloading-operators-using-member-functions/
