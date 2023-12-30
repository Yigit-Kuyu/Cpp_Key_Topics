#include <iostream>
#include <string>
#include <string_view>


// The interface of a class type defines how a user of the class type will interact with objects of the class type.
// Because only public members can be accessed from outside of the class type, the public members of a class type form its interface.
// For this reason, an interface composed of public members is sometimes called a "public interface".

// Requiring users of the class to use the "public interface" may seem more burdensome than providing public access to the member variables directly.
// But doing so provides a large number of useful benefits that help encourage class reusability and maintainability.


// To use an encapsulated class, you don’t need to know how it is implemented.
// You only need to understand its interface: what member functions are publicly available, what arguments they take, and what values they return.


class Employee // members are private by default
{
    // 1- making our member variables private
    std::string m_name{};
    char m_firstInitial{};

public:
    void setName(std::string_view name) // setter
    {
        m_name = name;
        m_firstInitial = name.front(); // use std::string::front() to get first letter of `name` ( 2- avoiding class invariant)
    }

    void print() const
    {
        std::cout << "Employee " << m_name << " has first initial " << m_firstInitial << '\n';
    }
};

// Note: Prefer implementing functions as non-members when possible (especially functions that contain application specific data or logic).

int main()
{
    Employee e{};
    e.setName("John");
    e.print();

    e.setName("Mark");
    e.print();

    return 0;
}






// Related page: https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/
