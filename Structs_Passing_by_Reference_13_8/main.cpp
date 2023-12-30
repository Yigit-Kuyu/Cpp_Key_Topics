#include <iostream>


// A big advantage of using structs over individual variables is that we can pass the entire struct to a function that needs to work with the members.
// Structs are generally passed by (const) reference to avoid making copies.


/*
To access a specific member variable, we use the member selection operator (operator.)
in between the struct variable name and the member name (for normal structs and references to structs),
or the member selection from pointer operator (operator->) (for pointers to structs)
*/


struct Employee
{
    int id {}; // zero initalizer
    int age {};  // zero initalizer
    double wage {};  // zero initalizer
};

void printEmployee(const Employee& employee) // note pass by reference here
{
    // Since references to an object act just like the object itself,
    // we can also use the member selection operator (.) to select a member from a reference to a struct:
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

int main()
{
    Employee joe { 14, 32, 24.15 };
    Employee frank { 15, 28, 18.27 };

    // Print Joe's information
    printEmployee(joe);

    std::cout << "joe id: " << joe.id << '\n'; // accessing struct member

    // Print Frank's information
    printEmployee(frank);

    return 0;
}





// Related page: https://www.learncpp.com/cpp-tutorial/passing-and-returning-structs/
