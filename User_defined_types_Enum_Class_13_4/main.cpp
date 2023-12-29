#include <iostream>


// Scoped enumerations work similarly to unscoped enumerations (User_defined_types_Enum_13_2),
// but have a primary difference: They are strongly scoped (the enumerators are only placed into the scope region of the enumeration).
// To make a scoped enumeration, we use the keywords "enum class".
// The rest of the scoped enumeration definition is the same as an unscoped enumeration definition.


// Unlike unscoped enumerations, which place their enumerators in the same scope as the enumeration itself,
// scoped enumerations place their enumerators only in the scope region of the enumeration.
// In other words, scoped enumerations act like a namespace for their enumerators.
// This built-in namespacing helps reduce global namespace pollution and the potential
// for name conflicts when scoped enumerations are used in the global scope.



// Although scoped enumerations use the class keyword, they aren’t considered to be a “class type”:

    enum class Color // "enum class" defines this as a scoped enumeration rather than an unscoped enumeration
    {
        red, // red is considered part of Color's scope region
        blue,
    };

    enum class Fruit
    {
        banana, // banana is considered part of Fruit's scope region
        apple,
    };



int main()
{


    Color color { Color::red }; // note: red is not directly accessible, we have to use Color::red
    Fruit fruit { Fruit::banana }; // note: banana is not directly accessible, we have to use Fruit::banana

    //std::cout << red << '\n';        // compile error: red not defined in this scope region
    //std::cout << Color::red << '\n'; // compile error: std::cout doesn't know how to print this (will not implicitly convert to int)




    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/
