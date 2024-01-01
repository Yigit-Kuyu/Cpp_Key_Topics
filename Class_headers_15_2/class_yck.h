#ifndef DATE_H
#define DATE_H


// Classes are defined in header files of the same name as the class (see Header_guard_6),
// and any member functions that can be defined outside of the class are put in a .cpp file of the same name as the class.


// the full definition of a class:
// (because the compiler typically needs to see the full definition of a class)
class Date
{
private:
    int m_year{};
    int m_month{};
    int m_day{};

public:
    Date(int year, int month, int day); // constructor

    void print() const; // forward declaration

    int getYear() const { return m_year; } // getter
    int getMonth() const { return m_month; } // getter
    int getDay() const { return m_day; } // getter
};

#endif


// Note: Functions defined inside the class definition are implicitly inline, which allows them to be #included
//       into multiple code files without violating the ODR.
// Functions defined outside the class definition are not implicitly inline.
// They can be made inline by using the inline keyword.
