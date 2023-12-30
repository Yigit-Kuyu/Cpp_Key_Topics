#include <iostream>


// From a technical standpoint, structs and classes are almost identical.
// Therefore, any example that is implemented using a struct could be implemented using a class, or vice-versa.
// However, from a practical standpoint, we use structs and classes differently.


// Classes are really the heart and soul of C++ -- they are so foundational that C++ was originally named “C with classes”!
// Once you are familiar with classes, much of your time in C++ will be spent writing, testing, and using them.


class Date       // we changed struct to class
{
public:          // and added this line, which is called an access specifier
    int m_day{}; // and added "m_" prefixes to each of the member names
    int m_month{};
    int m_year{};
};

void printDate(const Date& date)
{
    std::cout << date.m_day << '/' << date.m_month << '/' << date.m_year;
}

int main()
{
    Date date{ 4, 10, 21 };
    printDate(date);

    return 0;
}





// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-classes/
