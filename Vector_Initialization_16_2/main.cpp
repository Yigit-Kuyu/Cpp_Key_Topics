#include <vector>
#include <iostream>

// std::vector<int> declares a std::vector whose elements are of type int.

// The indexing starts with 0 rather than 1 (For example, primes[0]).
// In an array with N elements, the first element has index 0, the second has index 1, and the last element has index N-1.
// There is no element with index N!


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
    std::cout << &(primes[0]) << '\n';
    std::cout << &(primes[1]) << '\n';
    std::cout << &(primes[2]) << '\n';


    std::cout << " ##### Adjust specific length in vectors ###### " << '\n';
    std::vector<int> data( 10 ); // vector containing 10 int elements, value-initialized to 0


	// Copy init
    //std::vector<int> v1 = 10;     // 10 not an initializer list, copy init won't match explicit constructor: compilation error
	// List init
    std::vector<int> v2{ 0};    // { 10 } interpreted as initializer list, matches list constructor
    // Copy list init
    std::vector<int> v3 = { 10 }; // { 10 } interpreted as initializer list, matches list constructor

    std::cout << "The size of data is " << sizeof(data) << " bytes\n";
    std::cout << "The size of data is " << sizeof(v2) << " bytes\n";
    std::cout << "The size of data is " << sizeof(v3) << " bytes\n";
    std::cout << v3[5] << '\n';  /// Garip kaldım, ayrıca Array_Introduction_16_1'i doldurmayı unutma


	return 0;
}





// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/
