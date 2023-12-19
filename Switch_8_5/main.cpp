#include <iostream>

void printDigitName(int x)
{
    switch (x) // x evaluates to 3
    {
        case 1:
            std::cout << "One";
            break;
        case 2:

            std::cout << "Two";
            int x; //  Okey, no initialization
            break;
        case 3:
            {
            std::cout << "Three"; // execution starts here
            // int y{3}; // if you dont use paranthesis, you cannot use int x with initial value,
                      // because in the subsequent case, the variable does not exist and is not initialized.
                      // So, initialization is not allowed without case-based paranthesis.

            // return; // jump to the end of the "printDigitName" function
            break; // jump to the end of the switch block
            // If you dont put the statement to exit, switch will go inside each case after first match.
            }
        case 4:
            std::cout << "Four";
        default:
            std::cout << "Unknown";
            break;
    }

    // execution continues here
    std::cout << " Ah-Ah-Ah! ";
    std::cout << x;
    // std::cout << y; // out of scope
}

int main()
{
    printDigitName(2);
    std::cout << '\n';

    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/
