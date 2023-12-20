#include <iostream>


// Testing a small part of your code in isolation to ensure that “unit” of code is correct is called unit testing.
//  Each unit test is designed to ensure that a particular behavior of the unit is correct.



// We want to test the following function
bool isLowerVowel(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}



int testVowel() // Not called from anywhere right now, but here if you want to retest things later
{

    if (!isLowerVowel('a')) return 1; // test-1
    if (isLowerVowel('q')) return 2; // test-2

     return 0;
}

int main()
{
    bool test=true;


    // So here's our temporary tests to validate it works
    // Informal (Temporary) Testing:
    std::cout << isLowerVowel('a') << '\n'; // temporary test code, should produce 1
    std::cout << isLowerVowel('q') << '\n'; // temporary test code, should produce 0

    // In informal testing, after writing a unit of code (a function, a class, or some other discrete “package” of code),
    // you can write some code to test the unit that was just added, and then erase the test once the test passes.


   // Although writing temporary tests is a quick and easy way to test some code,
   // it can make more sense to preserve your tests so they can be run again in the future.
   // For example, instead of erasing your temporary test code, you could move the tests into a testVowel() function:

   if (test==true) // at any time to re-prove that you haven’t broken anything, especially in case of the code you modified.
   {
    int result { testVowel() };
    if (result != 0)
        std::cout << "testVowel() test " << result << " failed.\n";
    else
        std::cout << "testVowel() tests passed.\n";

   }


// Note: Because writing functions to exercise other functions is so common and useful,
// there are entire frameworks (called unit testing frameworks) that are designed to help simplify the process of writing,
// maintaining, and executing unit tests. Since these involve third party software, we won’t cover them here,
// but you should be aware they exist.




    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-testing-your-code/
// You can also find testing for-loop (Loop coverage):  https://www.learncpp.com/cpp-tutorial/code-coverage/
