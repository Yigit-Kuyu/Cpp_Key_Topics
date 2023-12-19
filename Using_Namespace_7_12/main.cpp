#include <iostream>

using namespace std;  // using-directive
using std::cout; // using-declaration

// Scoping:
// If a using-declaration or using-directive is used within a block,
// the names are applicable to just that block (it follows normal block scoping rules).


namespace a
{
	int x{ 10 };
}

namespace b
{
	int x{ 20 };
}

namespace c
{
	int x{ 25 };
}


int main()
{
	using namespace a;  // using-directive
	using namespace b; // // using-directive

	//std::cout << x << '\n'; // Error: the compiler is unable to determine whether
	                          // the x in main refers to a::x or b::x


    // use a using-declaration instead of a using-directive:
    using c::x;

    std::cout << x << '\n';



	return 0;
}


// Avoid using-directives (particularly using namespace std;), using-declarations are generally
// considered safe to use inside blocks.



// Related page: https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/
