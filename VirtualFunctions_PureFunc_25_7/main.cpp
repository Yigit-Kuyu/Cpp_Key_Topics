#include <string>


/*

So far, all of the virtual functions we have written have a body (a definition).
However, C++ allows you to create a special kind of virtual function called a pure virtual function (or abstract function) that has no body at all!

*/

class Animal // Abstract base class, because has pure virtual function
{
public:
    std::string m_name {};

    Animal(std::string name): m_name {name} {}; // default constructor with parameters
    Animal(){};

    std::string_view sayHi() const { return "Hi"; } // a normal non-virtual function

    virtual std::string_view getName() const { return "Base"; } // a normal virtual function

    virtual int getValue() const = 0; // a pure virtual function  (or abstract function)

    // int doSomething() = 0; // Compile error: can not set non-virtual functions to 0


    virtual ~Animal() = default; // generate a virtual default destructor


};

// Cow class was derived from Animal, but we did not define Cow::speak(), Cow is also an abstract base class.
class Cow: public Animal
{
public:
    Cow(std::string name)
        : Animal{ name }
    {
    }

    // We forgot to redefine getValue
};






int main()
{
     // Animal base {}; // We can't instantiate an abstract base class (Because there’s no definition for getValue()),Error
     // base.getValue(); // Error


    // Cow cow{ "Betsy" }; // Cow is an abstract base class and we can not create instances of abstract base classes, Error
    // std::cout << cow.getValue()  << '\n';


    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/
