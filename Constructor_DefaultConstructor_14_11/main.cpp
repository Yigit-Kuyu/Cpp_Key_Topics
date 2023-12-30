#include <iostream>


// A default constructor is a constructor that accepts no arguments.
// Typically, this is a constructor that has been defined with no parameters.

// If no user-declared constructors, the compiler will generate a public default constructor.
// In this case, when writing "Foo foo{}",
// the class generates implicitly:
// public:
//    Foo() {} // implicitly generated default constructor


// If you have user-declared constructor (not default one), the default constructer must be declerad if you write "Foo foo{}" or "Foo foo".

class Foo
{

private:
    int m_x {};
    int m_y {};

public:

    Foo() // default constructor
    {
        std::cout << "Foo default constructed\n";
    }



    /*
    //  A class should only have one default constructor. If more than one default constructor is provided, the compiler will give error:
       Foo(int x=1, int y=2) // default constructor with parameters
        : m_x { x }, m_y { y }
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }
    */


    Foo(int x, int y) // non-default constructor (Because constructors are functions, they can be overloaded)
        : m_x { x }, m_y { y }
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }



};

int main()
{
    Foo foo; // value initialization, calls Foo() default constructor
    Foo foo2;  // default initialization, calls Foo() default constructor
    Foo foo3{6, 7}; // Calls Foo(int, int) constructor

    return 0;
}





// Related page: https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments/
