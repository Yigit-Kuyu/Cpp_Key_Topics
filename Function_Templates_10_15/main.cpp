#include <iostream>

// Function templates are not actually functions -- their code isn’t compiled or executed directly.
// Instead, function templates have one job: to generate functions.

// Rather than using function overloading (writing the function again and again with different parameter type),
// function template is written once.


/*
int max(int x, int y) // Normal function definition
{
    return (x < y) ? y : x;
}
*/


// For above max function:
/*
Note that we use type int three times in this function (above max function):
once for parameter x, once for parameter y, and once for the return type of the function.

To create a function template, we’re going to do two things. First,
we’re going to replace our specific types with type template parameters.
In this case, because we have only one type that needs replacing (int),
we only need one type template parameter (which we’ll call T)
*/

// T is a type template parameter that is a placeholder for any type.
// This is done using what is called a template parameter declaration.
template <typename T> // this is the template parameter declaration
/* Note:
There is no difference between the typename and class keywords in this context.
You will often see people use the class keyword since it was introduced into the language earlier.
However, we prefer the newer typename keyword, because it makes it clearer that
the type template parameter can be replaced by any type (such as a fundamental type), not just class types.
*/
T max(T x, T y) // function template definition
{
    return (x < y) ? y : x;
}



// T is a type template parameter
// double is a non-template parameter
template <typename T1>
int someFcn (T1, double)
{
    return 5;
}



int main()
{

    // max<actual_type>(arg1, arg2)--> the actual type that will be used in place of template type T.
    std::cout << max<int>(1, 2) << '\n'; // instantiates and calls function max<int>(int, int),  replacing T with int.
    std::cout << max<double>(1, 2) << '\n'; // instantiates and calls function max<double>(double, double), replacing T with double.



    someFcn(1, 3.4); // matches someFcn(int, double)
    someFcn(1, 3.4f); // matches someFcn(int, double) -- the float is promoted to a double
    someFcn(1.2, 3.4); // matches someFcn(double, double)
    someFcn(1.2f, 3.4); // matches someFcn(float, double)
    someFcn(1.2f, 3.4f); // matches someFcn(float, double) -- the float is promoted to a double


    return 0;
}



// The compiler can use a single template to generate a family of related functions or classes,
// each using a different set of types.

// Templates can work with types that didn’t even exist when the template was written.
// This helps make template code both flexible and future proof!

// When we create our function template, we use placeholder types (also called type template parameters, or informally template types)
// for any parameter types, return types, or types used in the function body


// Related page: https://www.learncpp.com/cpp-tutorial/function-templates/
//               https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
