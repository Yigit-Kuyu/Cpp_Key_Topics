#include <iostream>


// Although C++ provides a default destructor for your classes
// if you do not provide one yourself, it is sometimes the case that you will want to provide your own destructor.

// Rule: Whenever you are dealing with inheritance, you should make any explicit destructors virtual.

class Base
{
public:
    virtual ~Base() // note: virtual
    {
        std::cout << "Calling ~Base()\n";
    }


    // If you don't write "virtual" keyword before class name in destruction (as below), compiler may warn you about the non-virtual destructor.
    // Because we really want the delete function to call Derived’s destructor and the program looks to see if the Base destructor is virtual.

    /*
       ~Base() // note: not virtual
    {
        std::cout << "Calling ~Base()\n";
    }
    */


};

class Derived: public Base
{
private:
    int* m_array {};

public:
    Derived(int length)
      : m_array{ new int[length] }
    {
    }

    virtual ~Derived() // note: virtual
    {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};

int main()
{
    Derived* derived { new Derived(5) };
    Base* base { derived };

    delete base;

    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/virtual-destructors-virtual-assignment-and-overriding-virtualization/
