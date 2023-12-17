

// g_x is internal to each file, main.cpp has no idea that a.cpp also has a variable named g_x (and vice versa).
constexpr int g_x { 2 }; // this internal g_x is only accessible within a.cpp

// // This function is declared as static, and can now be used only within this file
static int add(int x, int y)
{
    return x + y;
}





