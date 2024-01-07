#include <iostream>


// C++ supports two kinds of enumerations: unscoped enumerations (which we’ll cover now) and
// scoped enumerations (which we’ll cover later in this chapter).
// Unscoped enumerations are defined via the "enum" keyword.


// Each enumeration needs to be fully defined before we can use it (a forward declaration is not sufficient).

//  Enumerators are descriptive and symbolic constants, they are useful for enhancing code documentation and readability.
//  Enumerated types are best used when you have a smallish set of related constants,
//  and objects only need to hold one of those values at a time.



enum Color // this enum is defined in the global namespace
{
    red, // so red is put into the global namespace
    green,
    blue,
};


enum Feeling
{
    happy,
    tired,
    // blue, // error: naming collision with the above blue
};

namespace Feeling_1  // To avoid naming collision (as seen above Feeling), use namespace
{
    enum Feeling
    {
        happy,
        tired,
        blue, // Feeling::blue doesn't collide with Color::blue
    };
}

int main()
{
    // the enum is defined in the global namespace:
    Color apple { red }; // my apple is red
    Color raspberry { Color::red }; // also okay, accessing enumerator from scope of Color
    Feeling me { happy };

    Feeling_1::Feeling my{ Feeling_1::Feeling::blue }; // my=blue

     if (apple == red) // if the shirt is blue
        std::cout << "apple is red!"<< '\n';
    else
        std::cout << "apple is not red!";





    return 0;
}





// Related page: https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
