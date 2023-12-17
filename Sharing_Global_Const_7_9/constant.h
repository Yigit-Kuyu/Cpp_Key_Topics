#ifndef CONSTANTS_H
#define CONSTANTS_H


// Global symbolic constants should be namespaced
// (to avoid naming conflicts with other identifiers in the global namespace).
namespace constants
{
    // since the actual variables are inside a namespace, the forward declarations need to be inside a namespace as well
    extern const double pi; // forward declarations
    extern const double avogadro;  // forward declarations
    extern const double myGravity;  // forward declarations
}

#endif
