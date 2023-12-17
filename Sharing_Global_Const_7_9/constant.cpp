#include "constants.h"


// Global symbolic constants should be namespaced
// (to avoid naming conflicts with other identifiers in the global namespace).
namespace constants
{
    // global variables definitions:
    extern const double pi { 3.14159 };
    extern const double avogadro { 6.0221413e23 };
    extern const double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
}


// Any changes made to constants.cpp will require recompiling only constants.cpp,
//  not full code since all uses of these constants is linked to the version instantiated in constants.cpp.
