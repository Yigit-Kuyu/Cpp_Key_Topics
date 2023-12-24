#include <iostream>

#include <iostream>



// A major downside of functions that use an auto return type is that
// such functions must be fully defined before they can be used (a forward declaration is not sufficient).
auto foo();



// If you use auto in function, function body is needed.
auto foo2()
{
    return 5;
}


void addAndPrint(auto x, auto y) //  auto as function parameters.
{
    std::cout << x + y << '\n';
}




// Although auto is used, the function must return values of the same type.
/*
auto someFcn(bool b)  // Error
{
    // static_cast can also be used to avoid error.
    if (b)
        return 5; // return type int
    else
        return 6.7; // return type double
}
*/



int main()
{
    // the compiler has only seen a forward declaration at this point.
    //std::cout << foo() << '\n'; // Error

    std::cout << foo2() << '\n'; // No error, function definiton is used.


    addAndPrint(2, 3); // case 1: call addAndPrint with int parameters
    addAndPrint(4.5, 6.7); // case 2: call addAndPrint with double parameters


    return 0;
}

auto foo()
{
    return 5;
}





// Related page: https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/
