#include <iostream>
#include <string>

// We discussed that when passing an argument by value, a copy of the argument is made into the function parameter.
// For fundamental types (which are cheap to copy), this is fine. But copying is typically expensive for class types (such as std::string).



// Rule: The object being returned by reference must exist after the function returns:
const std::string& getProgramName_a()
{
    const std::string programName { "Calculator" }; // now a non-static local variable, destroyed when function ends

    return programName; //  dont return a local variable by reference !!!
}

// Rule: The object being returned by reference must exist after the function returns:
const std::string& getProgramName_b()
{
    static std::string programName { "Calculator" }; // has static duration, destroyed at end of program
    programName=programName+'I'; // modify static value
    return programName;
}

// Rule: The object being returned by reference must exist after the function returns:
const int& returnByConstReference(const int& ref)
{
    // ref=ref+1;  // error due to const
    return ref;
}


// The above rule is same to "return by address",
// this means the object being returned by address must exist after the function returns.

// Recommendation: Prefer return by reference over return by address unless the ability to return “no object” (using nullptr) is important.

int main()
{
    //std::cout << "This program is named " << getProgramName_a() <<'\n'; // warning: undefined behavior (segmentation fault)
    std::cout << "This program is named " << getProgramName_b() <<'\n'; // ok due to "static" keyword (Avoid returning references to non-const local static variables)

    // Don’t return non-const static local variables by reference:
    const std::string&  id1 { getProgramName_b()}; // id1 is a reference
    const std::string&  id2 { getProgramName_b() }; // id2 is a reference
    // id1 and id2 give same results because they are referencing the same object (the static variable "programName"):
    std::cout << "This program id1: " << id1 <<'\n'; // id1 and id2 give same results
    std::cout << "This program id2:" << id2 <<'\n'; // id1 and id2 give same results

     //  It is important for id1 and id2:
     //  If a function returns a reference, and that reference is used to initialize,
     //  the return value will be copied.
     //  This also defeats the purpose of returning a value by reference !!!!!!!
     //  So, dont use returned reference for initialization.



    // The object being returned by reference must exist after the function returns:
    int xx{5};
    int& ref1 {xx}; // extends lifetime
    const int& c=returnByConstReference(ref1);
    // c=c+1; // error due to const
    std::cout << c << '\n'; // okay, return value const int&

    ref1=ref1+2; // modify reference
    std::cout << "new ref1: "<< ref1  << '\n'; // changed to 7
    std::cout << "new xx: "<< xx  << '\n'; // changed to 7


    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/
