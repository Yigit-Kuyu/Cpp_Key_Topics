#include <iostream>
#include <string> // For std::string and std::getline


// To read a full line of input into a string,
// you’re better off using the std::getline() function instead of std::cin.


int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};

    //  The std::ws input manipulator tells std::cin to ignore any leading whitespace before extraction.

    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your favorite color: ";
    std::string color{};
    std::getline(std::cin >> std::ws, color); // read a full line of text into color

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';
    std::cout << name << " has " << name.length() << " characters\n";

    return 0;
}


// When a std::string is passed to a function by value,
// the std::string function parameter must be instantiated and initialized with the argument.
// This results in an expensive copy.  Initializing and copying a std::string is slow.
//  We’ll discuss what to do instead (use std::string_view)
// In most other cases, do not return a std::string by value, as doing so will make an expensive copy.



// Related Topic: https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
