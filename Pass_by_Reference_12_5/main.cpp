#include <iostream>


// Why create an alias (reference) to a variable when you can just use the variable itself?
// You can find the answer in main code.


// One way to avoid making an expensive copy of an argument
// when calling a function is to use pass by reference instead of pass by value.
// Because the reference acts as an alias for the argument, no copy of the argument is made.


// Recommendation: Favor passing by const reference over passing by non-const reference unless
// you have a specific reason to do otherwise (e.g. the function needs to change the value of an argument).

void printValue_string_const_ref(const std::string& y) // y is now a const reference, pass by const reference
{
    //y="hiiiiii"; // // error: not allowed, y is const
    std::cout << "const string ref: " << y << '\n';
}


void printValue_string_ref(std::string& y) // pass by reference
{
    y="hiiiiii"; // this modifies the actual object x1
    std::cout << "changed string ref: " << y << '\n';
} // y is destroyed here



void printValue_string(std::string y) // pass by value
{
    std::cout << y << '\n';
} // y is destroyed here


void printValue_int(int y) // pass by value
{
    std::cout << y << '\n';
} // y is destroyed here




int main()
{
    int x { 2 };
    // This means that when we called the function, we made a copy of our argument’s value,
    // only to use it briefly and then destroy it! Fortunately, because fundamental types are cheap to copy, this isn’t a problem.
    printValue_int(x); // x is passed by value (copied) into parameter y (inexpensive)

    std::string x1 { "Hello, world!" }; // x is a std::string

    // Most of the types provided by the standard library (such as std::string) are class types. Class types are usually expensive to copy.
    printValue_string(x1); // x1 is passed by value (copied) into parameter y (expensive)

    printValue_string_ref(x1);

    std::cout<< "main cout: " << x1 << '\n' ; // x1 is changed because referenced y is changed in the function.

    int xx = 10;

    // ref is a reference to xx, because ref acts as an alias for xx.
    int& ref = xx;

    // Value of xx is now changed to 20
    ref = 20;
    std::cout << "x = " << xx << '\n';

    // Value of xx is now changed to 30
    xx = 30;
    std::cout << "ref = " << ref << '\n';






    const std::string z{"ali"};
    //printValue_string_ref(z); // error: z is a non-modifiable lvalue
    //printValue_string_ref("ali"); // error: "ali" is an rvalue
    printValue_string_const_ref(z);
    printValue_string_const_ref("ali");




    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/
//               https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/

