#include <iostream>


/*
    The destructor must have the same name as the class, preceded by a tilde (~).
    The destructor can not take arguments.
    The destructor has no return type (same as constructor)
    A class can only have a single destructor.
*/


// Generally you should not call a destructor explicitly
// (as it will be called automatically when the object is destroyed),
// since there are rarely cases where you’d want to clean up an object more than once.



class Simple
{
private:
    int m_id {};

public:
    Simple(int id) // Default construtor with parameters
        : m_id { id }
    {
        std::cout << "Constructing Simple " << m_id << '\n';
    }

    ~Simple() // here's our destructor
    {
        std::cout << "Destructing Simple " << m_id << '\n';
    }

    int getID() const { return m_id; } // getter
};

int main()
{
    // Allocate a Simple
    Simple simple1{ 1 }; // each Simple object is destroyed, the destructor is called
    {
        Simple simple2{ 2 }; // each Simple object is destroyed, the destructor is called
    } // simple2 dies here

    int a=simple1.getID();
    std::cout<< "member of the simple1:" << a << '\n';

    return 0;
} // simple1 dies here




// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-destructors/
