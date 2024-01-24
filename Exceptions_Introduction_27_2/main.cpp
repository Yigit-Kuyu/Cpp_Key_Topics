#include <iostream>
#include <string>
#include <cmath> // for sqrt() function


/*
A throw statement is used to signal that an exception or error case has occurred (think of throwing a penalty flag).
Signaling that an exception has occurred is also commonly called raising an exception.

Some examples:

throw -1; // throw a literal integer value
throw ENUM_INVALID_INDEX; // throw an enum value
throw "Can not take square root of negative number"; // throw a literal C-style (const char*) string
throw dX; // throw a double variable that was previously defined
throw MyException("Fatal Error"); // Throw an object of class MyException

*/

// Try blocks and catch blocks work together -- a try block detects any exceptions
// that are thrown by statements within the try block,
//  and routes them to a catch block with a matching type for handling.


void ExceptionFunc(int x)
{

try // Look for exceptions that occur within try block and route to attached catch block(s)
    {
        // If the user entered a negative number, this is an error condition
        if (x < 0.0)
            throw "Can not take sqrt of negative number"; // throw exception of type const char*, because we’re within a try block

        // Otherwise, print the answer
        std::cout << "The sqrt of " << x << " is " << std::sqrt(x) << '\n';
    }
    catch (const char* exception) // catch exceptions of type const char*
    {
        std::cerr << "Error: " << exception << '\n';
    }

}



int main()
{
    try
    {
        // Statements that may throw exceptions you want to handle go here
        throw -1; // an exception is raised
        std::cout << "This never prints\n"; // no print
    }
    catch (int x) //  catch handler
    {
        // Any exceptions of type int thrown within the above try block get sent here
        std::cerr << "We caught an int exception with value: " << x << '\n';
    }
    catch (double) // no variable name since we don't use the exception itself in the catch block below
    {
        // Any exceptions of type double thrown within the above try block get sent here
        std::cerr << "We caught an exception of type double" << '\n';
    }
    catch (const std::string&) // catch classes by const reference
    {
        // Any exceptions of type std::string thrown within the above try block get sent here
        std::cerr << "We caught an exception of type std::string" << '\n';
    }

    // Once the exception was handled, the program continued as normal after the catch blocks,
    //  printing “Continuing on our merry way”.
    std::cout << "Continuing on our merry way\n";


    /*
    Output:

    We caught an int exception with value -1
    Continuing on our merry way

    */


    int m=3;
    ExceptionFunc(m);

    return 0;



}



// Related page: https://www.learncpp.com/cpp-tutorial/basic-exception-handling/
