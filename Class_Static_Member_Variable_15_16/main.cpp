#include <iostream>

// For more info about static variables, see Static_local_variable_7_10


// All of the members belong to the class (instead of object of the class), and class declarations usually
// have global scope, a pure static class is essentially the equivalent of declaring functions
// and global variables in a globally accessible namespace.
// So, Instead of writing a class with all static members, consider writing a normal class and
//  instantiating a global instance of it (global variables have static duration).

// Making static members inline allows them to be initialized inside the class definition.

struct Something
{
    //  All static members are instantiated only once.
    static int s_value; // now static (must be public for outside access)
    //static inline int s_value{ 4 }; // a static inline variable can be defined and initialized directly
    int a;

    Something() : a(5) {} // 1) initialize 'a' with constructor

};


// You can initialize static member variables inside and outside of the class
// using the scope resolution operator ::.  However, for non-static member variables like "a",
// you should initialize them inside the class constructor or directly
//  when creating instances of the class.
int Something::s_value{ 1 }; // initialize s_value to 1
// int Something::a{ 5 }; // Error, you cannot initialize "a" out of class

int main()
{
    Something first{};
    Something second{};

    first.s_value = 2;
    first.a=20; // 2) initialize "a" via instance object

// Because s_value is a static member variable, s_value is shared
// between all objects of the class.
// Consequently, first.s_value is the same variable as second.s_value.

    std::cout << first.s_value << '\n'; // output:2
    std::cout << second.s_value << '\n';  // output:2
    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/static-member-variables/
