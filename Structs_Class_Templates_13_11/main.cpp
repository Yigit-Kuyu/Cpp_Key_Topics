#include <iostream>

// A “class type” is a struct, class, or union type. So, struct templates can be count as class templates for simplicity.
// Everything here applies equally well to classes.


// class type template:
template <typename T> // use the keyword typename
struct Pair
{
    T first{}; // type template parameter will match anything
    T second{};
};

// function template:
template <typename T> // use the keyword typename
constexpr T max(Pair<T> p)
{
    return (p.first < p.second ? p.second : p.first);
}

int main()
{
    Pair<int> p1{ 5, 6 };        // instantiates Pair<int> and creates object p1
    std::cout << p1.first << ' ' << p1.second << '\n';

    Pair<double> p2{ 1.2, 3.4 }; // instantiates Pair<double> and creates object p2
    std::cout << p2.first << ' ' << p2.second << '\n';

    Pair<double> p3{ 7.8, 9.0 }; // creates object p3 using prior definition for Pair<double>
    std::cout << p3.first << ' ' << p3.second << '\n';


    Pair<int> p4{ 5, 6 };
    // // max<actual_type>(arg1, arg2)--> the actual type that will be used in place of template type T. (see Function_Templates_10_15)
    std::cout << max<int>(p4) << " is larger\n"; // explicit call to max<int> (template type T is replaced with int)

    Pair<double> p5{ 1.2, 3.4 };
    std::cout << max(p5) << " is larger\n"; // call to max<double> (template type T is replaced with double)


    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/class-templates/
