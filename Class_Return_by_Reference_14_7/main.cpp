#include <iostream>
#include <string>

// The object being returned by reference must exist after the function returns (see Return_by_reference_and_by_address_12_12).
// Member functions can also return by reference, and they follow the same rules.

class Employee
{
	std::string m_name{};

public:
	void setName(std::string_view name) { m_name = name; }

	// Why we use const after function name, see Class_Const_Member_Function_14_4
	const std::string& getName() const { return m_name; } //  getter returns by const reference  (prefered)

	//const auto& getName() const { return m_name; } // uses `auto` to deduce return type from m_name (can be used)
	// For type deduction of auto, see Type_deduction_auto_forReference_and_Pointers_12_14
};


//Do not return non-const references to private data members:
class Foo
{
private:
    int m_value{ 4 }; // private member

public:
    auto& value() { return m_value; } // returns a non-const reference (don't do this)
};



int main()
{
	Employee joe{}; // joe exists until end of function
	joe.setName("Joe");
	std::cout << joe.getName()<< '\n'; // returns joe.m_name by reference


	// Do not return non-const references to private data members:
    Foo f{};                // f.m_value is initialized to default value 4
    f.value() = 5;          // The equivalent of m_value = 5

    std::cout << f.value(); // prints 5

	return 0;
}

// Related page: https://www.learncpp.com/cpp-tutorial/member-functions-returning-references-to-data-members/#google_vignette



