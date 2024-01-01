#include "class_yck.h"
#include <iostream>


// The advantage of writting definitions in cpp file is that
// If you change the code in a .cpp file, only that .cpp file needs to be recompiled.


// Date constructor definition
Date::Date(int year, int month, int day)
    : m_year{ year }
    , m_month{ month }
    , m_day{ day }
{
}

void Date::print() const // print function definition
{
    std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
};
