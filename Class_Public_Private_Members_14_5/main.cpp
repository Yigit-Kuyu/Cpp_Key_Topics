#include <iostream>
#include <string>
#include <string_view>



// The technical and practical difference between structs and classes:
// A class defaults its members to private, whereas a struct defaults its members to public. That’s it.

//  As a rule of thumb, use a struct when all of the following are true:
// -You have a simple collection of data that doesn’t benefit from restricting access.
// -Aggregate initialization is sufficient.
//  Use a class otherwise.




// The members of a struct are public by default.
// The members of a class are private by default.



class Date // now a class instead of a struct
{
    // class members are private by default, can only be accessed by other members
    int m_year {};     // private by default
    int m_month {};    // private by default
    int m_day {};      // private by default

    void print() const // private by default
    {
        // private members can be accessed in member functions
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};



class Person
{
private: // private access specifier
    std::string m_name{};

public: // public access specifier (a member function can directly access private members)
    void kisses(const Person& p) const
    {
        std::cout << m_name << " kisses " << p.m_name << '\n';
    }

    void setName(std::string_view name)
    {
        m_name = name;
    }
};




int main()
{
    //Date today { 2020, 10, 14 }; // compile error: can no longer use aggregate initialization becasuse default is private

    // private members can not be accessed by the public
    //today.m_day = 16; // compile error: the m_day member is private
    //today.print();    // compile error: the print() member function is private


    Person joe;
    joe.setName("Joe");
    Person kate;
    kate.setName("Kate");
    joe.kisses(kate); // output: Joe kisses Kate



    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/
