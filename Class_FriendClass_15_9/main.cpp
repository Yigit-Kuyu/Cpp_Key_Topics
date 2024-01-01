#include <iostream>

// A friend class is a class that can access the private and protected members of another class.


class Storage
{
private:
    int m_nValue {};
    double m_dValue {};
public:
    Storage(int nValue, double dValue)
       : m_nValue { nValue }, m_dValue { dValue }
    { }


    // Friendship is not reciprocal. Just because Display is a friend of Storage does not mean
    // Storage is also a friend of Display. If you want two classes to be friends of each other,
    // both must declare the other as a friend.

    // Make the Display class a friend of Storage
    friend class Display;
};

class Display
{
private:
    bool m_displayIntFirst {};

public:
    Display(bool displayIntFirst)
         : m_displayIntFirst { displayIntFirst }
    {
    }

    // Because Display is a friend of Storage, Display members can access the private members of Storage
    void displayStorage(const Storage& storage)
    {
        if (m_displayIntFirst)
            std::cout << "access private members of storage class (true condition): "<<storage.m_nValue << ' ' << storage.m_dValue << '\n';
        else // display double first
            std::cout <<  "access private members of storage class (false condition): "<<storage.m_dValue << ' ' << storage.m_nValue << '\n';
    }

    void setDisplayIntFirst(bool b)
    {
         m_displayIntFirst = b;
    }
};

int main()
{
    Storage storage { 5, 6.7 };
    Display display { false };

    display.displayStorage(storage);

    display.setDisplayIntFirst(true);
    display.displayStorage(storage);

    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/
