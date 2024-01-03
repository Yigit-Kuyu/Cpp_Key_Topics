#include <vector>
#include <iostream>

// std::vector<int> declares a std::vector whose elements are of type int.

// The indexing starts with 0 rather than 1 (For example, primes[0]).
// In an array with N elements, the first element has index 0, the second has index 1, and the last element has index N-1.
// There is no element with index N!


struct Foo
{
    //std::vector<int> v1(8); // compile error: direct initialization not allowed for member default initializers
    std::vector<int> v{ std::vector<int>(8) }; // ok
};

int main()
{
	// Value initialization (uses default constructor)
	std::vector<int> empty{}; // vector containing 0 int elements

    // List construction (uses list constructor)
	std::vector<int> prim{ 2, 3, 5, 7 };          // vector containing 4 int elements with values 2, 3, 5, and 7
	std::vector vowels { 'a', 'e', 'i', 'o', 'u' }; // vector containing 5 char elements with values 'a', 'e', 'i', 'o', and 'u'.

    std::vector primes { 2, 3, 5, 7, 11 }; // hold the first 5 prime numbers (as int)

    std::cout << " ##### Access data in vectors ###### " << '\n';
    std::cout << "The first prime number is: " << primes[0] << '\n';
    std::cout << "The second prime number is: " << primes[1] << '\n';
    std::cout << "The sum of the first 5 primes is: " << primes[0] + primes[1] + primes[2] + primes[3] + primes[4] << '\n';

    std::cout << " ##### Vectors are contiguous in memory ###### " << '\n';
    std::cout << "An int is " << sizeof(int) << " bytes\n";
    std::cout << &(primes[0]) << '\n';// primes[]: access element in vector
    std::cout << &(primes[1]) << '\n';
    std::cout << &(primes[2]) << '\n';


    std::cout << " ##### Adjust specific length in vectors ###### " << '\n';
    std::vector<int> data( 10 ); // vector containing 10 int elements, value-initialized to 0


	// Copy init
    //std::vector<int> v1 = 10;     // 10 not an initializer list, copy init won't match explicit constructor: compilation error


    // the 10 is not treated as an element value; instead, it represents the size of the vector.
    std::vector<int> v2(10); // 10 not an initializer list, matches explicit single-argument constructor



    //  v2 has only one element at index 0, and its value is 0.
     std::vector<int> v3{ 0};   // List init,  { 10 } interpreted as initializer list, matches list constructor

    // v3 has only one element at index 0, and its value is 10.
    std::vector<int> v4 = { 10 }; // Copy list init, { 10 } interpreted as initializer list, matches list constructor

    std::cout << "The size of data is " << sizeof(data) << " bytes\n";
    std::cout << "The size of data is " << sizeof(v3) << " bytes\n";
    std::cout << "The size of data is " << sizeof(v4) << " bytes\n";

    // The behavior of accessing elements beyond the vector's size is undefined. It may lead to unexpected results,
    // and the compiler is not required to detect or warn about such situations.
    // In my case, the compiler is providing a default-initialized value (zero) for the out-of-bounds access:
    std::cout << v4[5] << '\n';  // output: 0 (no error)

    //  const std::vector must be initialized, and then cannot be modified:
    const std::vector<int> prime { 2, 3, 5, 7, 11 };

    // One of the biggest downsides of std::vector is that it cannot be made constexpr.
    // If you need a constexpr array, use std::array.

	return 0;
}





// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
