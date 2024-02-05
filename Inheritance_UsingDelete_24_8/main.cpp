#include <iostream>



class Base
{
private: // our member is now private
    int m_id {};

public:
    Base(int id=0)
        : m_id{ id }
    {
    }

    int getId() const { return m_id; }

protected:
    void printValue() const { std::cout << m_id; }   //  Because Base::printValue() has been declared as protected,
                                                    //   it can only be called by Base or its derived classes.
                                                   //    The public can not access it.



};

class Derived: public Base
{
private: // our member is now private
    double m_cost;

public:
    Derived(double cost=0.0, int id=0)
        : Base{ id } // Call Base(int) constructor with value id!
        , m_cost{ cost }
    {
    }

     double getCost() const { return m_cost; }

     int getId() const = delete; // mark this function as inaccessible


    // Base::printValue was inherited as protected, so the public has no access
    // But we're changing it to public via a using declaration
    using Base::printValue; // note: no parenthesis here
};

int main()
{


    Derived derived{ 1.3, 5 }; // use Derived(double, int) constructor
    derived.printValue(); // access protected member due to  using Base::printValue


    Base base {3};
	std::cout << base.getId() << '\n';

	//std::cout << derived.getId() << '\n'; // won't work because getId() has been deleted!


    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/hiding-inherited-functionality/
