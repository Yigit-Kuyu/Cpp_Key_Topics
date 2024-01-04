#include <iostream>
#include <vector>

// Since std::array and C-style arrays are fixed-size array types,
// std::vector significantly different than most of the other array types: the ability to resize itself after it has been instantiated.
// std::vector is a dynamic array. This mean a dynamic array (also called a resizable array) is an array whose size can be changed after instantiation.


/*
The length vs capacity for a std::vector:
In the context of a std::vector, capacity is how many elements the std::vector has allocated storage for,
and length is how many elements are currently being used.
Note: Most of the time you won’t need to use the capacity() function.

*/



int main()
{
    std::vector v{ 0, 1, 2 }; // create vector with 3 elements (length is initially 3)
    std::cout << "The length is: " << v.size() << '\n'; // Vector indexing is based on length, not capacity

    // Change the capacity (reallocation) of storage is expensive, avoid unnecessary reallocations.
    v.resize(5);              // resize to 5 elements (increase capacity to 5)
    std::cout << "The length is: " << v.size() << '\n';

    for (auto i : v)
        std::cout << i << '\n';

    std::cout << "Capacity: " << v.capacity() << " Length: "	<< v.size() << '\n';



    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/stdvector-resizing-and-capacity/
