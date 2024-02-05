#include <iostream>




class Person
{
private:
    std::string m_name;
    int m_age {};

public:
    Person(std::string_view name = "", int age = 0)
        : m_name{ name }, m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }

};
// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
private:
    double m_battingAverage {};
    int m_homeRuns {};

public:
    BaseballPlayer(std::string_view name = "", int age = 0,
        double battingAverage = 0.0, int homeRuns = 0)
        : Person{ name, age } // call Person(std::string_view, int) to initialize these fields
        , m_battingAverage{ battingAverage }, m_homeRuns{ homeRuns }
    {
    }

    double getBattingAverage() const { return m_battingAverage; }
    int getHomeRuns() const { return m_homeRuns; }
};


/////////////////////////////////////////////////////////////////////////////////////////


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
};

int main()
{
    // When derived.getID() is called, the compiler looks to see if function getID() has been defined in the Derived class. It hasn’t.
    // Then it starts looking in the inherited classes (which in this case is Base). Base has defined an getID() function,
    // so it uses that one. In other words, Base::getID() was used because Derived::getID() doesn’t exist.
    //However, if we had defined Derived::getID() in the Derived class, it would have been used instead.

    Derived derived{ 1.3, 5 }; // use Derived(double, int) constructor
    std::cout << "Id: " << derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';


    std::cout << '\n';


    BaseballPlayer pedro{ "Pedro Cerrano", 32, 0.342, 42 };
    std::cout << pedro.getName() << '\n';
    std::cout << pedro.getAge() << '\n';
    std::cout << pedro.getBattingAverage() << '\n';
    std::cout << pedro.getHomeRuns() << '\n';


    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/
