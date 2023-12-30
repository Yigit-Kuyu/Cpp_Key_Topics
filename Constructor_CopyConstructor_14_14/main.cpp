#include <iostream>

// A copy constructor is a constructor that is used to initialize an object with an existing object of the same type.
// After the copy constructor executes, the newly created object should be a copy of the object passed in as the initializer.

// A copy constructor should not do anything other than copy an object.


// In summary, the default constructor with no parameters-> Fraction() : m_numerator{numerator}, m_denominator{denominator} {}
//             the copy constructor->  Fraction(const Fraction& fraction): m_numerator{numerator}, m_denominator{denominator} {}


class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
    }

    void print()
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }

};



class Fraction_forCopyConstructor
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction_forCopyConstructor(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
    }

    // Copy constructor
    Fraction_forCopyConstructor(const Fraction_forCopyConstructor& fraction)
        // Initialize our members using the corresponding member of the parameter
        : m_numerator{ fraction.m_numerator }
        , m_denominator{ fraction.m_denominator }
    {
        std::cout << " \n Copy constructor called: \n"; // just to prove it works
    }

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };  // Calls Fraction(int, int) constructor

    // If you do not provide a copy constructor for your classes, C++ will create a public implicit copy constructor for you.
    Fraction fCopy { f }; // What constructor is used here?--> copy constructor (implicitly created) (fCopy is a copy of f)
    f.print();
    fCopy.print();

    Fraction_forCopyConstructor f1 { 5, 3 };  // Calls Fraction(int, int) constructor
    Fraction_forCopyConstructor fCopy1 { f1 }; // Calls Fraction(const Fraction&) copy constructor

    f1.print();
    fCopy1.print();

    // Note: Prefer the implicit copy constructor, unless you have a specific reason to create your own.


    return 0;
}





// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/
