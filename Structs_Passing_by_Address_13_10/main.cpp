#include <iostream>

// With normal variables or references, we can access objects directly.
// However, because pointers hold addresses, we first need to dereference the pointer to get the object before we can do anything with it.


struct Employee
{
    int id{};
    int age{};
    double wage{};
};


struct Paw
{
    int claws{};
};

struct Animal
{
    std::string name{};
    Paw paw{};
};

int main()
{
    Employee joe{ 1, 34, 65000.0 };

    ++joe.age;
    joe.wage = 68000.0;

    // This member selection from pointer operator (->) works identically to the member selection operator (.)
    // but does an implicit dereference of the pointer object before selecting the member:
    Employee* ptr{ &joe };
    std::cout << (*ptr).id << '\n'; // Not great but works: First dereference ptr, then use member selection
    std::cout << ptr->id << '\n'; // Better: use -> to select member from pointer to object

    // Note: When doing member access through a pointer, always use the -> operator instead of the . operator.


    // Mixing pointers and non-pointers to members:
    Animal puma{ "Puma", { 5 } };
    Animal* ptr1{ &puma };

    // ptr is a pointer, use ->
    // paw is not a pointer, use .

    std::cout << (ptr1->paw).claws << '\n';



    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references/
