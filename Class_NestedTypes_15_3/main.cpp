#include <iostream>
#include <string>
#include <string_view>


// Define any nested types at the top of your class type.

// Note that inside the class we can just use IDType, but outside the class
// we must use the fully qualified name Employee::IDType.

class Employee
{
public:
    using IDType = int;
    double f{10};

private:
    std::string m_name{};
    IDType m_id{};
    double m_wage{};

public:
    Employee(std::string_view name, IDType id, double wage)
        : m_name { name }
        , m_id { id }
        , m_wage { wage }
    {
    }

    const std::string& getName() { return m_name; }
    IDType getId() { return m_id; } // can use unqualified name within class
};

int main()
{
    Employee john { "John", 1, 45000 };
    Employee::IDType id { john.getId() }; // must use fully qualified name outside class (Employee::IDType->int)

    std::cout << john.getName() << " has id: " << id << '\n';
    std::cout<< john.f << std::endl; // access public member of the class outside

    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/nested-types-member-types/
