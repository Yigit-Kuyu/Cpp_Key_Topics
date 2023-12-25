#include <iostream>


// with a forward declaration and a function definition,
// the default argument can be declared in either the forward declaration or the function definition, but not both.
// void print(int x, int y=20, int z=10);// forward declaration --> error

// Note: Best practice is to declare the default argument in the forward declaration and not in the function definition,

// If a parameter is given a default argument, all subsequent parameters (to the right) must also be given default arguments.
// void print(int x=10, int y=20, int z)--> not allowed
void print(int x, int y=20, int z=10)
{
    std::cout << "Values: " << z << " " << y  << '\n';
}



// Functions with default arguments may be overloaded:

void print(std::string)
{
}

void print(char=' ')
{
}



int main()
{
    print(1, 2, 3); // all explicit arguments

    // Function overloading
    print("Hello, world"); // resolves to print(std::string)
    print('a'); // resolves to print(char)
    print(); // resolves to print(char)



    return 0;
}

// Related page: https://www.learncpp.com/cpp-tutorial/default-arguments/
