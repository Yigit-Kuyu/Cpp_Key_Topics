#include <iostream>


// To have a constructor initialize members, we do so using a member initializer list (often called a “member initialization list”).
// Do not confuse this with the similarly named “initializer list” that is used to initialize aggregates with a list of values.

/*

Members can be initialized in a few different ways:

    -If a member is listed in the member initializer list, that initialization value is used
    -Otherwise, if the member has a default member initializer, that initialization value is used

*/

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y) // member initializer list are always initialized in the order in which they are defined inside the class.
        : m_x { x },
          m_y { y } // here's our member initialization list
        //m_x = x; // incorrect: this is an assignment, not an initialization
        //m_y = y; // incorrect: this is an assignment, not an initialization

    {
        std::cout << "Foo constructed\n";
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo{ 6, 7 }; // output: Foo(6, 7) constructed
    foo.print(); // output: Foo(6, 7)

    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
