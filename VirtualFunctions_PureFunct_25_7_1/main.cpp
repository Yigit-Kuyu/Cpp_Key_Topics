// C++ Program to illustrate the abstract class and virtual
// functions
#include <iostream>
using namespace std;


 // This code is from different source (not learncpp)


 // Sometimes implementation of all functions cannot be provided in a base class
 //because we don’t know the implementation. Such a class is called an abstract class.

 /*

 For example, let Shape be a base class. We cannot provide the implementation of function draw() in Shape,
 but we know every derived class must have an implementation of draw().
 Similarly, an Animal class doesn’t have the implementation of move() (assuming that all animals move), but all animals must know how to move.

 */

 /*

 A pure virtual function (or abstract function) in C++ is a virtual function for which we can have an implementation,
 But we must override that function in the derived class,
 otherwise, the derived class will also become an abstract class.
 A pure virtual function is declared by assigning 0 in the declaration.


 */


class Base {
    // private member variable
    int x;

public:
    // pure virtual function
    virtual void fun() = 0;

    // getter function to access x
    int getX() { return x; }
};

// This class inherits from Base and implements fun()
class Derived : public Base {
    // private member variable
    int y;

public:
    // implementation of the pure virtual function
    void fun() { cout << "fun() called" << '\n'; }
};

int main(void)
{
    // creating an object of Derived class
    Derived d;
    Base& r{d};
    Base* p=&d;


    d.fun();   // calling the fun() function directly
    r.fun();   // calling the fun() function using reference
    p->fun();   // calling the fun() function using pointer

    return 0;
}





// Related page: https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/
