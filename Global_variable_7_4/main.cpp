#include <iostream>


// Avoid using non-const global variable.
// For const variable, “encapsulate” the variable via namespace:
namespace constants
{

    // Global const variables have internal linkage by default, gravity doesn’t need to be static.
    constexpr double gravity { 9.8 };
}


int g_x;       // no explicit initializer (zero-initialized by default)
int g_y {};    // value initialized (resulting in zero-initialization)
int g_z { 1 }; // list initialized with specific value

//const int c_g_x;     // error: constant variables must be initialized
//constexpr int c_g_w; // error: constexpr variables must be initialized

const int c_g_y { 1 };     // const global variable g_y, initialized with a value
constexpr int c_g_z { 2 }; // constexpr global variable g_z, initialized with a value


void doSomething()
{
    // global variables can be seen and used everywhere in the file
    std::cout << g_y << '\n';
    std::cout << g_z << '\n';
}

int main()
{
    doSomething();

    // global variables can be seen and used everywhere in the file
    std::cout << g_y << '\n';
    std::cout << g_z << '\n';

    // Variable shadowing (local variable in its scope hides global variable)
    int g_z{}; // this assigns value 3 to main block "g_z", not outer block "g_z"
    g_z=3;
    std::cout << "variable shadowing: " << g_z << '\n';
    // Note: Avoid variable shadowing

    std::cout << constants::gravity << '\n';

    return 0;
}


// g_y and g_z goes out of scope her


// Relaated page: https://www.learncpp.com/cpp-tutorial/introduction-to-global-variables/
