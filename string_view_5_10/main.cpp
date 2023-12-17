#include <iostream>
#include <string>
#include <string_view>

using namespace std;


// Since Initializing and copying a std::string is slow,
// std::string_view provides read-only access to an existing string.

// Use a std::string, You need a string that you can modify and need to store user-inputted text.

// std::string_view can be used as the return value of a function. However, this is often dangerous.

void print_string_view(std::string_view str) // string_view accept many different types of string arguments
{
    std::cout << str << '\n';
}

void print_string(std::string str)
{
	std::cout << str << '\n';
}


std::string getName()
{
    std::string s { "Alexx" };

    // Returning a std::string containing the string “Alex”.
    // Return values are temporary objects that are destroyed at the end of the full expression
    // containing the function call.

    return s;
}



int main()
{
    print_string_view("Hello, world!"); // call with C-style string literal

    std::string s2{ "Hello, world!" };
    print_string_view(s2); // call with std::string

    std::string_view s3 { s2 };
    print_string_view(s3); // call with std::string_view


    // std::string_view will not convert to std::string:

    // print_string((sv);   // compile error: won't implicitly convert std::string_view to a std::string

    print_string(static_cast<std::string>(s2)); // okay: we can explicitly cast a std::string_view to a std::string


    // Assignment changes what the std::string_view is viewing:

    std::string name { "Alex" };
    std::string_view sv { name }; // sv is now viewing name
    std::cout << sv << '\n'; // prints Alex

    sv = "John"; // sv is now viewing "John" (does not change "name" variable)
    std::cout << sv << '\n'; // prints John

    name="Ali";
    std::cout << sv << '\n'; // prints John

    sv=name;
    std::cout << sv << '\n'; // prints Ali


     // Improperly using std::string_view:

       std::string_view name2 { getName() }; // name initialized with return value of function
       std::cout << "name2: "<<name2 << '\n'; // undefined behavior

        using namespace std::string_literals;
        std::string_view name3 { "Alex"s }; // "Alex"s creates a temporary std::string
        std::cout << "name3: "<<  name3 << '\n'; // undefined behavior

        // Do not initialize a std::string_view with a std::string literal.



       	// View modification functions:

       	std::string_view str{ "Peach" }; // Initialize with C-style string is okay,
       	                                 // Because "Peach" exists for the entire program.
        std::cout << str << '\n';

        // Remove 1 character from the left side of the view
        str.remove_prefix(1);
        std::cout << str << '\n';

        // Remove 2 characters from the right side of the view
        str.remove_suffix(2);
        std::cout << str << '\n';

        str = "Peach"; // reset the view
        std::cout << str << '\n';


    return 0;
}

// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/
