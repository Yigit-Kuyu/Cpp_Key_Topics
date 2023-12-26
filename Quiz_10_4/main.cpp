#include <iostream>

template <typename T>
int count(T) // This is the same as int count(T x), except we're not giving the parameter a name since we don't use the parameter
{
    static int c { 0 }; // This is static inti pay attention !!!
    return ++c;
}

int main()
{
    std::cout << count(1) << '\n';
    std::cout << count(1) << '\n';
    std::cout << count(2.3) << '\n';
    std::cout << count<double>(1) << '\n';

    // Output:
    /*
        1
        2
        1
        2
    */



    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/

