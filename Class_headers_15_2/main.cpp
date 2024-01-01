#include <iostream>
#include "class_yck.h"


// As you learned in Header_guard_6,  you can put function declarations in a header files.
// Then you can #include those functions declarations into multiple code files.
// Classes are no different. A class definitions can be put in a header files, and then #included into any other files that want to use the class type.
// Unlike functions, which only need a forward declaration to be used, the compiler typically needs to see the full definition of a class.
// So our header files usually contain the full definition of a class rather than just a forward declaration of the class.

// If you define a class inside a source (.cpp) file, that class is only usable within that particular source file.
// In larger programs, it’s common that we’ll want to use the classes we write in multiple source files.


using namespace std;

int main()
{
    const Date d{ 2015, 10, 14 };
    d.print();

    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/classes-and-header-files/
