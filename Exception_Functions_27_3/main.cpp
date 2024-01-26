#include <cmath> // for sqrt() function
#include <iostream>

/*
One of the most useful properties of exception handling is that the throw statements
do NOT have to be placed directly inside a try block. Instead, exceptions can be thrown from anywhere in a function,
and those exceptions can be caught by the try block of the caller
*/


// A modular square root function
double mySqrt(double x)
{
    // If the user entered a negative number, this is an error condition
    if (x < 0.0)
        throw "Can not take sqrt of negative number"; // throw exception of type const char* (an exception is raised)

    if (x>0.0)
        throw 0;  // No handler in main (an exception is raised)

    return std::sqrt(x);
}

int main()
{
    std::cout << "Enter a number: ";
    double x {};
    std::cin >> x; // If you give positive number, the code is directly terminated since there is no handler of "throw 0".
                   // If you give negative number, the code goes to catch handler.

    try // Look for exceptions that occur within try block and route to attached catch block(s)
    {
        double d = mySqrt(x);
        std::cout << "The sqrt of " << x << " is " << d << '\n';
    }
    catch (const char* exception) // catch exceptions of type const char*
    {
        std::cerr << "Error Yck: " << exception << std::endl;
    }
    catch(...)  // catch-all handler: any of the functions it calls throws an exception that is not handled, it will be caught by this catch-all handler.
    {
        std::cerr << "Abnormal termination\n";
    }



   std::cout << "No handler does not result in direct termination due to catch(...)" << '\n';

    return 0;
}





/*
Related page: https://www.learncpp.com/cpp-tutorial/exceptions-functions-and-stack-unwinding/
              https://www.learncpp.com/cpp-tutorial/uncaught-exceptions-catch-all-handlers/
*/
