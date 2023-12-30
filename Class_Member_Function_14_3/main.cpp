#include <iostream>

// We are using structs to show examples of member functions -- but everything we show here applies equally well to classes.
// In C, structs only have data members, not member functions, In C++ it has both.

// With non-member functions usage:
struct Date_NoMember
{
    // here are our member variables
    int year {};
    int month {};
    int day {};
};

// With non-member functions usage:
void print(const Date_NoMember& date)
{
    // member variables accessed using member selection operator (.)
    std::cout << "non-member function access: "<< date.year << '/' << date.month << '/' << date.day <<'\n';
}





// Member functions must be declared inside the class type definition,
// and can be defined inside or outside of the class type definition.
// To keep things simple, we’ll define our member functions inside the class type definition for now.

// With member functions usage:
struct Date_Member
{
    int year {};
    int month {};
    int day {};

    // Member functions defined inside the class type definition are implicitly inline,
    // so they will not cause violations of the one-definition rule if the class type definition is included into multiple code files.
    void print() // defines a member function named print
    {
        std::cout << "member function access: "<< year << '/' << month << '/' << day <<'\n';
    }
};




// Just like non-member functions, member functions can be overloaded, so long as each member function can be differentiated.
// With  overloaded member functions usage:
struct Date_OverloadedMember
{
    int year {};
    int month {};
    int day {};

    void print()
    {
        std::cout << "overloaded member function access-1: " <<year << '/' << month << '/' << day<<'\n';
    }

    void print(std::string_view prefix)
    {
        std::cout <<  "overloaded member function access-2: "<< prefix << year << '/' << month << '/' << day<<'\n';
    }

};



int main()
{
    Date_NoMember today { 2020, 10, 14 }; // aggregate initialize our struct
    today.day = 16; // member variables accessed using member selection operator (.)
    print(today);   // non-member function accessed using normal calling convention



    Date_Member today1 { 2020, 10, 14 }; // aggregate initialize our struct
    today1.day = 16; // member variables accessed using member selection operator (.)
    today1.print();  // member functions also accessed using member selection operator (.)


    Date_OverloadedMember today2 { 2020, 10, 14 };

    today2.print(); // calls Date::print()
    std::cout << '\n';

    today2.print("The date is: "); // calls Date::print(std::string_view)
    std::cout << '\n';





   return 0;

}

// Related page: https://www.learncpp.com/cpp-tutorial/member-functions/
