#include <string>
#include <iostream>
#include <typeinfo>



/*
Top-level const and low-level const:

const int x;    // this const applies to x, so it is top-level
int* const ptr; // this const applies to ptr, so it is top-level

const int& ref; // this const applies to the object being referenced, so it is low-level
const int* ptr; // this const applies to the object being pointed to, so it is low-level


*/


const std::string& getConstRef()
{
   const std::string& x{"ali"};
   return x;
};


const double foo()
{
    return 5.6;
}



std::string* getPtr()
{
    std::string x{"YcK"};
    std::string* ptr {&x};
    return ptr;

};



int main()
{

    const double cd{ 7.8 };

    auto x{ cd };    // double (const dropped)
    auto y{ foo() }; // double (const dropped)

    // Type deduction drops references:
    auto ref1{ getConstRef() };        // std::string (reference and top level const dropped)
    std::cout << "type of address ref1: "<< typeid(&ref1).name() << '\n';


    const auto ref2{ getConstRef() };  // const std::string (reference dropped, const reapplied)
    std::cout << "type of address ref2: "<< typeid(&ref2).name() << '\n';

    // For ref3, normally the reference would be dropped first,
    // but since we’ve reapplied the reference, it is not dropped. That means the type is still const std::string&
    auto& ref3{ getConstRef() };       // const std::string& (reference reapplied, low-level const not dropped)

    // For ref4, since the type is already deduced as a reference to const (as seen in ref3), reapplying const here is redundant.
    // That said, using const here makes it explicitly clear that our result will be const
    // (whereas in the ref3 case, the constness of the result is implicit and not obvious).
    const auto& ref4{ getConstRef() }; // const std::string& (reference and const reapplied)

    // Note: If you want a const reference, reapply the const qualifier even when it’s not strictly necessary,
    // as it makes your intent clear and helps prevent mistakes.


    // Unlike references, type deduction does not drop pointers:
    auto ptr1{ getPtr() }; // std::string*


    return 0;
}

// Related page: https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
