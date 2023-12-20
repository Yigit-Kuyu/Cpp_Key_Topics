#include <cassert> // for assert()
#include <cmath> // for std::sqrt
#include <iostream>


// An assertion is an expression that will be true unless there is a bug in the program.
// If the expression evaluates to true, the assertion statement does nothing.
// This makes it very easy to tell not only what the problem was, but where in the code the problem occurred.
// When an assertion evaluates to false, your program is immediately stopped.
// This gives you an opportunity to use debugging tools to examine the state of your program and determine why the assertion failed.
// Furthermore, asserts should (ideally) never be encountered in production code (because your code should already be thoroughly tested).



std::string carCheck(std::string type)
{
  assert(type=="a" && "Car could not be found in database"); // Only 'a' type car in the database

  std::cout<<" given car is in the database" << std::endl;

  return type;


}

int main()
{
  std::cout << "Took " << carCheck("a") << "\n";

  return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/
