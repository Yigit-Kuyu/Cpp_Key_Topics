#include <cstddef> // for std::size_t
#include <exception> // for std::exception
#include <iostream>
#include <limits>
#include <string> // for this example


//  std::exception is a small interface class designed to serve as a base class to any exception thrown by the C++ standard library.


/*
Much of the time, when an exception is thrown by the standard library, we won’t care whether it’s a bad allocation, a bad cast, or something else.
We just care that something catastrophic went wrong and now our program is exploding.
Thanks to std::exception, we can set up an exception handler to catch exceptions of type std::exception,
and we’ll end up catching std::exception and all of the derived exceptions together in one place. Easy!
*/



int main()
{
    try
    {
        // Your code using standard library goes here to catch by std::exception
        // We'll trigger one of these exceptions intentionally for the sake of the example
        std::string s;
        s.resize(std::numeric_limits<std::size_t>::max()); // will trigger a std::length_error or allocation exception
    }
    // This handler will catch std::exception and all the derived exceptions too
    catch (const std::exception& exception)
    {

        /*
          what():
          The one thing worth noting is that std::exception has a virtual member function named what() that returns a C-style string description of the exception.
          Most derived classes override the what() function to change the message.
          Note that this string is meant to be used for descriptive text only -- do not use it for comparisons,
          as it is not guaranteed to be the same across compilers.
        */
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }

    return 0;
}


    //  Output: Standart exception: basic_string::_M_replace_aux



// Related page: https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/
