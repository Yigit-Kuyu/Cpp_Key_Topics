#include <iostream>
#include <string>


// In modern C++, most things that can be done with pass by address are better accomplished through other methods.
// Follow this common maxim: “Pass by reference when you can, pass by address when you must”.
// That means, if pass by address is not must, choose pass by reference.

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(std::string* ptr) // The function parameter is a pointer that holds the address of str
{
    if (!ptr) // if ptr is a null pointer, early return back to the caller. Because you cannot deference (*ptr) null pointer.
        return;

    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
    *ptr="aliveli"; // if you write "const std::string* ptr" as function parameter, you cannot modify ptr.

}




int main()
{
    std::string str{ "Hello, world!" };

    std::string* ptr{ &str };

    printByValue(str); // pass str by value, makes a copy of str
    printByReference(str); // pass str by reference, does not make a copy of str

    printByAddress(&str); // pass str by address, does not make a copy of str --> "Hello, world!"
    printByAddress(ptr); // pass str by address, does not make a copy of str --> "aliveli"


    std::cout<< "changed value in function: " << str << std::endl; // "Pass by address" like "pass by reference" allows the function to modify the argument’s value

    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/pass-by-address/
