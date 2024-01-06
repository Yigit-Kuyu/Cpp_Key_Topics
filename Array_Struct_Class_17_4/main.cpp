#include <array>
#include <iostream>


// Note: We’ll use structs to illustrate our points in this lesson. The material applies equally well to classes.



struct House
{
    int number{};
    int stories{};
    int roomsPerStory{};
};

int main()
{

    // Defining and assigning to a std::array of structs:
    std::array<House, 3> houses{};

    houses[0] = { 13, 1, 7 };  // assignment
    houses[1] = { 14, 2, 5 }; // assignment
    houses[2] = { 15, 2, 4 }; // assignment

    for (const auto& house : houses)
    {
        std::cout << "House number " << house.number
                  << " has " << (house.stories * house.roomsPerStory)
                  << " rooms.\n";
    }

    // Initializing a std::array of structs:
        constexpr std::array houses1 { // use CTAD to deduce template arguments <House, 3>
            House{ 13, 1, 7 },
            House{ 14, 2, 5 },
            House{ 15, 2, 4 }
        };

    for (const auto& house : houses1)
    {
        std::cout << "House1 number " << house.number
            << " has " << (house.stories * house.roomsPerStory)
            << " rooms.\n";
    }


    // Doesn't work: you cannot use assignment case for initializing:
    /*
    constexpr std::array<House, 3> houses2 { // initializer for houses
    { 13, 1, 7 }, // initializer for C-style array member with implementation_defined_name (like default contructor)
    { 14, 2, 5 }, // ?
    { 15, 2, 4 }  // ?
    };
    */

    // Work: you can use assignment case with extra braces for initializing:
    constexpr std::array<House, 3> houses2 { // initializer for houses
    { // extra set of braces to initialize the C-style array member with implementation_defined_name
        { 13, 4, 30 }, // initializer for array element 0
        { 14, 3, 10 }, // initializer for array element 1
        { 15, 3, 40 }, // initializer for array element 2
     }
    };


    for (const auto& house : houses2)
    {
        std::cout << "House2 number " << house.number
                  << " has " << (house.stories * house.roomsPerStory)
                  << " rooms.\n";
    }




    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/stdarray-of-class-types-and-brace-elision/
