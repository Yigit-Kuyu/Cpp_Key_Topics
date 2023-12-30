#include <iostream>



struct Date
{
    int year {};
    int month {};
    int day {};

    void incrementDay()
    {
        ++day;
    }

       void print()
    {
        std::cout << year << '/' << month << '/' << day << '\n';
    }

     // void const print_1(): does not work, because a const before the function name applies to the return type.
     // void print_1() const: does work, because a const after the function name applies to the member function itself.
         void print_1() const // now a const member function
    {
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};


int main()
{
    const Date today { 2020, 10, 14 }; // const


    // Modifying the data members of const objects is disallowed:
    //today.day += 1;        // compile error: can't modify member of const object
    //today.incrementDay();  // compile error: can't call member function that modifies member of const object

    // Const objects cannot call non-const member functions (The compiler won’t let us call a non-const member function on a const object):
    //today.print();  // compile error: can't call non-const member function
    today.print_1();   // ok: const object can call const member function

    // Const member functions can be called on non-const objects:
    Date today_nonConst { 2020, 10, 14 }; // non-const
    today_nonConst.print();  // ok: can call const member function on non-const object

    // Note: A member function that does not (and will not ever) modify the state of the object should be made const,
    // so that it can be called on both const and non-const objects.


    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/
