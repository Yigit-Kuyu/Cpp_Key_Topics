#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}


template <typename T, typename U> // We're using two template type parameters named T and U
T max_multiparameters(T x, U y) // x can resolve to type T, and y can resolve to type U
{
    return (x < y) ? y : x; // uh oh, we have a narrowing conversion problem here
}

// To avoid narrowing conversation problem, use auto as return type:
/*
auto max_multiparameters(T x, U y) // x can resolve to type T, and y can resolve to type U
{
    return (x < y) ? y : x; // No narrowing conversion problem here
}
*/


int main()
{
    // T is one type, it is not possible that T is int and T is double at the same call.
    //std::cout << max(2, 3.5) << '\n';  // compile error--> max(int, double), the complier will not find.

    std::cout << max(static_cast<double>(2), 3.5) << '\n'; // convert our int to a double so we can call max(double, double)

    std::cout << max<double>(2, 3.5) << '\n'; // // we've explicitly specified type double,


    // T can be an int and U can be a double. The compiler will happily instantiate max<int, double>(int, double)
    std::cout << max_multiparameters(2, 3.5) << '\n'; // but we have a narrowing conversion problem here


    return 0;
}

// Related page: https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/
