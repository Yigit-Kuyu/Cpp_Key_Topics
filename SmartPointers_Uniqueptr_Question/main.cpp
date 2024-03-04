#include <iostream>
#include <memory> // for std::unique_ptr

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};

void printFraction(const Fraction* ptr)
{
	if (ptr)
		std::cout << *ptr << '\n';
	else
		std::cout << "No fraction\n";
}

int main()
{
	//auto* ptr{ new Fraction{ 3, 5 } };
	auto ptr=std::make_unique<Fraction>(3, 5); // When you use std::make_unique<Fraction>(3, 5), it returns a std::unique_ptr<Fraction>, not a raw pointer,

	//  You can't directly pass ptr (when ptr is a std::unique_ptr) to a function expecting a raw pointer.
	//  Use ".get()" with unique pointer to obtain raw pointer.
	printFraction(ptr.get());

	//delete ptr;

	return 0;
}




// Question-1: Convert the following program from using a normal pointer to using std::unique_ptr where appropriate.
// https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
