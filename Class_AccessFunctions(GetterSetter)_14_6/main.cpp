#include <iostream>


// The codes work, since I changed the name of the main folder, that will give an error.
// To use this code, copy and paste it into clean C++ page.

// An access function is a trivial public member function whose job is to retrieve or change the value of a private member variable.
// Access functions come in two flavors: getters and setters. Getters (also sometimes called accessors) are public member functions
// that return the value of a private member variable. Setters (also sometimes called mutators) are public member functions
// that set the value of a private member variable.

// Getters are usually made const,
// so they can be called on both const and non-const objects. Setters should be non-const, so they can modify the data members.


class Date
{
private:
    int m_year { 2020 };
    int m_month { 10 };
    int m_day { 14 };

public:
    void print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }

    int getYear() const { return m_year; }        // getter for year, “get” prefix only
    void setYear(int year) { m_year = year; }     // setter for year, “set” prefix only

    int getMonth() const  { return m_month; }     // getter for month, get” prefix only
    void setMonth(int month) { m_month = month; } // setter for month, “set” prefix only

    int getDay() const { return m_day; }          // getter for day, get” prefix only
    void setDay(int day) { m_day = day; }         // setter for day, “set” prefix only
};


int main()
{
    Date d{};
    d.setYear(2021);
    std::cout << "The year is: " << d.getYear() << '\n';

    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/access-functions/
