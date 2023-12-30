#include <iostream>

/*
Making a constructor explicit cannot be used following:

    -Copy (and move) constructors (as these do not perform conversions).
    -Default constructors with no parameters (as these are only used to convert {} to a default object, not something we need to restrict).

*/



class Dollars
{
private:
    int m_dollars{};

public:
    Dollars(int d)
        : m_dollars{ d }
    {
    }

    int getDollars() const { return m_dollars; }
};


class Dollars_explicit
{
private:
    int m_dollars{};

public:
    explicit Dollars_explicit(int d)
        : m_dollars{ d }
    {
    }

    int getDollars() const { return m_dollars; }
};

void print1(Dollars d)
{
    std::cout << "$" << d.getDollars();
}

void print2(Dollars_explicit d)
{
    std::cout << "$" << d.getDollars();
}





int main()
{

    // When we call print(5), the Dollars(int) converting constructor will be used to convert 5 into a Dollars object.
    print1(5); // output: $5 (implicitly convert our int value to a Dollars object)

    // It would be better if our print(Dollars) function could only be called with a Dollars object.
    // To address such issues, we can use the explicit keyword to tell the compiler that a constructor should not be used as a converting constructor.
    // print2(5); // // compilation error because Dollars_explicit(int d) is explicit



    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/
