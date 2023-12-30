#include <iostream>



/*  How do we initialize (aggregate initialization) a class with private member variables?

A constructor is a special member function that is automatically called after a non-aggregate class type object is created.

When a non-aggregate class type object is defined, the compiler looks to see if it can find an accessible constructor
that is a match for the initialization values provided by the caller (if any).

    -If an accessible matching constructor is found, memory for the object is allocated, and then the constructor function is called.
    -If no accessible matching constructor can be found, a compilation error will be generated.

*/

/* Naming constructors

Unlike normal member functions, constructors have specific rules for how they must be named:

    -Constructors must have the same name as the class (with the same capitalization). For template classes, this name excludes the template parameters.
    -Constructors have no return type (not even void).
*/



class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y) // here's our constructor function that takes two initializers
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }


    Foo() // constructors must be non-const
    {
        m_x = 5; // okay to modify members in non-const constructor
    }

    int getX() const { return m_x; } // const, getter



    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo{ 6, 7 }; // calls Foo(int, int) constructor, output: Foo(6, 7) constructed

    // This is because although our Foo(int, int) constructor function was called,
    // it did not actually initialize the members. So, the output is Foo(0, 0).
    foo.print(); // output: Foo(0, 0)


    const Foo foo2{}; // calls Foo()
    std::cout << "x value of foo2: "<< foo2.getX() << "\n";



    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-constructors/
