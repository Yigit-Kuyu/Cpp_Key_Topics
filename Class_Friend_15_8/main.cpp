#include <iostream>


// In C++, a friend is a class or function (member or non-member)
// that has been granted full access to the private and protected members of another class.
// In all other regards, the friend function is a normal function.



class Accumulator
{
private:
    int m_value { 0 };

public:
    void add(int value) { m_value += value; }

    // Here is the friend declaration that makes non-member function void print(const Accumulator& accumulator) a friend of Accumulator
    friend void print(const Accumulator& accumulator);
    int Getvalue() const { return m_value; } // added getter
};

void print(const Accumulator& accumulator)
{
    // Because print() is a friend of Accumulator
    // it can access the private members of Accumulator
    std::cout << "print function: "<< accumulator.m_value <<'\n';
}


void print1(const Accumulator& accumulator) // no longer a friend of Accumulator
{
    std::cout << "print1 function: "<<accumulator.Getvalue(); // use access function instead of direct access
}


int main()
{
    Accumulator acc{};
    acc.add(5); // add 5 to the accumulator

    print(acc); // call the print() non-member function (with friend)
    print1(acc); // call the print() non-member function (with getter)

    return 0;
}


// Note: Prefer to implement a function as a non-friend when possible and reasonable.


// Related page: https://www.learncpp.com/cpp-tutorial/friend-non-member-functions/
