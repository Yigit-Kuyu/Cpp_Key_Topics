#include <iostream>
#include <random> // for std::mt19937

// The Mersenne Twister (MT) PRNG (Pseudo-random number generator) is probably the most popular PRNG across
// all programming languages. Although it is a bit old by today’s standards,
// it generally produces quality results and has decent performance.
// The random library has support for two MT types:

//mt19937 is a Mersenne Twister that generates 32-bit unsigned integers
//mt19937_64 is a Mersenne Twister that generates 64-bit unsigned integers


int main()
{
	std::mt19937 mt{}; // Instantiate a 32-bit Mersenne Twister

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << mt() << '\t'; // generate a random number

		// If we've printed 5 numbers, start a new row
		if (count % 5 == 0)
			std::cout << '\n';

        std::cin.get(); // for debuggig press enter
	}

	return 0;
}



// The related page: https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/
