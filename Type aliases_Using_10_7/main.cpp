#include <iostream>

// using is a keyword that creates an alias for an existing data type. To create such a type alias, we use the using keyword.
// In modern C++, the convention is to name type aliases (or any other type) that you define yourself starting with a capital letter,
// and using no suffix (for example, use "Miles", "Miles_t" instead.)


//  type alias identifiers follow the same scoping rules as variable identifiers:
// a type alias defined inside a block has block scope and is usable only within that block,
// whereas a type alias defined in the global namespace has global scope and is usable to the end of the file.
// In the below example, Miles and Speed are only usable in the main() function.

int main()
{

    using Miles = long; // define Miles as an alias for type long
    using Speed = long; // define Speed as an alias for type long

    Miles distance { 5 }; // distance is actually just a long
    Speed mhz  { 3200 };  // mhz is actually just a long

    // The following is syntactically valid (but semantically meaningless)
    distance = mhz;

    return 0;
}



// When should we use type aliases?
/*
One of the primary uses for type aliases is to hide platform specific details.
On some platforms, an int is 2 bytes, and on others, it is 4 bytes.
Thus, using int to store more than 2 bytes of information can be potentially dangerous
when writing platform independent code.

Because char, short, int, and long give no indication of their size, it is fairly common
for cross-platform programs to use type aliases to define aliases that include the type’s size in bits.
For example, int8_t would be an 8-bit signed integer, int16_t a 16-bit signed integer, and int32_t a 32-bit signed integer.
Using type aliases in this manner helps prevent mistakes and makes it more clear about
what kind of assumptions have been made about the size of the variable.

In order to make sure each aliased type resolves to a type of the right size,
type aliases of this kind are typically used in conjunction with preprocessor directives:

#ifdef INT_2_BYTES
using int8_t = char;
using int16_t = int;
using int32_t = long;
#else
using int8_t = char;
using int16_t = short;
using int32_t = int;
#endif



*/




// Related page: https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
