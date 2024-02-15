#include <iostream>
#include <string_view>

// polymorphism refers to the ability of an entity to
// have multiple forms (the term “polymorphism” literally means “many forms”).


class Base
{
public:
    virtual std::string_view getName() const { return "Base"; } // note addition of virtual keyword
};

class Derived: public Base
{
public:
    virtual std::string_view getName() const { return "Derived"; }
};

int main()
{

    /*
    rBase is a reference to the Base portion of a Derived object,
    when rBase.getName() is evaluated, it would normally resolve to Base::getName().
    However, Base::getName() is virtual, which tells the program to go look and see
    if there are any more-derived versions of the function available for a Derived object.
    In this case, it will resolve to Derived::getName()
    */

    Derived derived {};
    Base& rBase{ derived }; // Note that virtual function resolution only works when a virtual member function is called
                            // through a pointer or reference to a class type object.
    std::cout << "rBase is a " << rBase.getName() << '\n'; // output: Derived


    /*
    Calling a virtual member function directly on an object (direct assigning a Derived object to a Base object), not through a pointer or reference,
    will always invoke the member function belonging to the same type of that object.
    */
    Base r1Base{derived};
    std::cout << "r1Base is a " << r1Base.getName() << '\n'; // output: Base

    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/virtual-functions/
