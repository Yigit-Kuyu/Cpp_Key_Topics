#include <iostream>


//  A break statement terminates the switch or loop, and execution continues at the first statement beyond the switch or loop.
 // A return statement terminates the entire function that the loop is within, and execution continues at point
 // where the function was called.

int breakOrReturn()
{
    while (true) // infinite loop
    {
        std::cout << "Enter 'b' to break or 'r' to return: ";
        char ch{};
        std::cin >> ch;

        if (ch == 'b')
            break; // execution will continue at the first statement beyond the loop

        if (ch == 'r')
            return 1; // return will cause the function to immediately return to the caller (in this case, main())
    }


    // execution will continue here after the break
    std::cout << "We broke out of the loop\n";

    return 0;
}

int main()
{
    int returnValue{ breakOrReturn() };
    std::cout << "Function breakOrReturn returned " << returnValue << '\n';

    // The continue statement provides a convenient way to end the current iteration of a loop without terminating the entire loop:
    for (int countt{ 0 }; countt < 10; ++countt)
    {
        // if the number is divisible by 4, skip this iteration
        if ((countt % 4) == 0)
            continue; // go to next iteration

        // If the number is not divisible by 4, keep going
        std::cout << countt << '\n';

        // The continue statement jumps to here (bottom of the loop)
    }


    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/break-and-continue/
