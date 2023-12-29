#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

struct Foo
{
    int a{};
    int b{};
    int c{};
};

int main()
{
    Employee joe {}; // the name joe refers to the entire struct object (which contains the member variables).

    // To access a specific member variable, we use the member selection operator (operator.):
    joe.age = 32;
     std::cout << joe.age << '\n'; // print joe's age

     // Aggregate initialization:
     Employee frank = { 1, 32, 60000.0 }; // list initialization using braced list (aggregate initialization)
     // Alternative:
     // Employee frank {};
     // frank={ 1, 32, 60000.0 }; // aggregate initialization

     Employee yck { 2, 28 }; // yck.wage will be value-initialized to 0.0


    frank.age = 28; // modifying struct member variable
    if (joe.age> frank.age)
        std::cout << "Joe is older than Frank\n";
    else
        std::cout << "Frank is older than John\n";

    //Initializing a struct with another struct of the same type:
    Foo foo={ 1, 2, 3 }; // Or--> Foo foo { 1, 2, 3 };

    Foo x = foo; // copy initialization
    Foo y(foo);  // direct initialization
    Foo z {foo}; // list initialization

    std::cout << x.a << ' ' << y.b << ' ' << z.c << '\n';


    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-structs-members-and-member-selection
//               https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/
