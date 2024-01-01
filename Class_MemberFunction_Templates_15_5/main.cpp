#include <ios>       // for std::boolalpha
#include <iostream>



// For ODR rule of the definition of class functions inside or outside of the class, see Class_headers_15_12
// For the general usage of templates in class, see Structs_Class_Templates_13_11


template <typename T>
class Pair
{
private:
    T m_first{};
    T m_second{};

public:
    // When we define a member function (constructor in this case) inside the class definition,
    // the template parameter declaration belonging to the class applies.
    Pair(const T& first, const T& second) // Because class data members are type T.
        : m_first{ first }                // T might be expensive to copy,
        , m_second{ second }              //  it’s safer to pass by const reference than by value.
    {
    }

    bool isEqual(const Pair<T>& pair);
};

// When we define a member function outside the class definition,
// we need to resupply a template parameter declaration
template <typename T>
bool Pair<T>::isEqual(const Pair<T>& pair)
{
    return m_first == pair.m_first && m_second == pair.m_second;
}

int main()
{
    Pair p1{ 5, 6 };
    std::cout << std::boolalpha << "isEqual(5, 6): " << p1.isEqual( Pair{5, 6} ) << '\n';
    std::cout << std::boolalpha << "isEqual(5, 7): " << p1.isEqual( Pair{5, 7} ) << '\n';

    return 0;
}





// Related page: https://www.learncpp.com/cpp-tutorial/class-templates-with-member-functions/


