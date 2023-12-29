#include <iostream>
#include <string>
#include <string_view>

/*
As a rule of thumb, pass fundamental types by value, and class (or struct) types by const reference.

Other common types to pass by value: enumerated types and std::string_view.
Other common types to pass by (const) reference: std::string, std::array, and std::vector.
*/

// In C++, a string argument will typically be a std::string, a std::string_view, or a C-style string/string literal.
// One question that comes up often in modern C++: when writing a function that has a string parameter,
// should the type of the parameter be const std::string& or std::string_view?
// In most cases, std::string_view is the better choice. Prefer passing strings using std::string_view (by value)
// instead of const std::string&.
// Note that a const std::string& parameter only handles std::string arguments inexpensively.


void printSV(std::string_view sv)
{
    std::cout << sv << '\n';
}

void printS(const std::string& s)
{
    std::cout << s << '\n';
}

int main()
{
    std::string s{ "Hello, world" };
    std::string_view sv { s };

    // Pass to `std::string_view` parameter
    printSV(s);              // ok: inexpensive conversion from std::string to std::string_view
    printSV(sv);             // ok: inexpensive copy of std::string_view
    printSV("Hello, world"); // ok: inexpensive conversion of C-style string literal to std::string_view

    // pass to `const std::string&` parameter
    printS(s);              // ok: inexpensive bind to std::string argument
    // printS(sv);             // compile error: cannot implicit convert std::string_view to std::string
    printS(static_cast<std::string>(sv)); // bad: expensive creation of std::string temporary
    printS("Hello, world"); // bad: expensive creation of std::string temporary

    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/
