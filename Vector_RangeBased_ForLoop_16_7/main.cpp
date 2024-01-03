#include <iostream>
#include <vector>


/*

for (element_declaration : array_object)
   statement;


When a range-based for-loop is encountered, the loop will iterate through each element in array_object. For each iteration,
the value of the current array element will be assigned to the variable declared in element_declaration, and then statement will execute.

*/



int main()
{
    std::vector fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    //for (int num : fibonacci) // num should have the same type as the array elements
    for (auto num : fibonacci) // compiler will deduce type of num to be `int` becuase fibonacci has elements of type int
       std::cout << num << '\n';



    using namespace std::literals; // for s suffix for std::string literals
    std::vector words{ "peter"s, "likes"s, "frozen"s, "yogurt"s }; // std::vector<std::string>
    for (const auto& word : words) // Copying a std::string is expensive, which is why we typically pass std::string to functions by const reference.
        std::cout << word << ' ';


    // Note: Normally we’d use auto for cheap-to-copy types, and const auto& for expensive-to-copy types.
    //       But with ranged-based for-loops, many developers believe it is preferable to always use const auto& because it is more future-proof.

    std::cout << '\n';

    return 0;
}





// Related page: https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/
