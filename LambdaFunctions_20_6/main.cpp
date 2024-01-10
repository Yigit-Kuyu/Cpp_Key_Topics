#include <functional>
#include <iostream>
#include <algorithm>
#include <array>

/*

The syntax for lambdas:

[ captureClause ] ( parameters ) -> returnType
{
    statements;

}


The capture clause can be empty if no captures are needed.
The parameter list can be empty if no parameters are required.
The return type is optional, and if omitted, auto will be assumed.

*/

//#################  if we want to pass a lambda to a function, there are 3 options:


// Option 1: use a `std::function` parameter
void repeat1(int repetitions, const std::function<void(int)>& fn) //  function parameter is a std::function
{
    for (int i{ 0 }; i < repetitions; ++i)
        fn(i);
}

// Option 2: use a function template with a type template parameter
template <typename T>
void repeat2(int repetitions, const T& fn) // T matches the actual type of the lambda. The parameters and return type of T are not obvious.
{
    for (int i{ 0 }; i < repetitions; ++i)
        fn(i);
}

// Option 3: use the abbreviated function template syntax (C++20)
void repeat3(int repetitions, const auto& fn) // auto to invoke the abbreviated function template syntax. This generates a function template identical to option 2.
{
    for (int i{ 0 }; i < repetitions; ++i)
        fn(i);
}



bool greater(int a, int b)
{
  // Order @a before @b if @a is greater than @b.
  return a > b;
}



int main()
{
    auto lambda = [](int i) {
    std::cout << i << '\n';
  };

  repeat1(3, lambda);
  repeat2(3, lambda);
  repeat3(3, lambda);


  /*
   You dont need to write your own lambdas,
   because the standard library comes with many basic callable objects that can be used instead.
  */
  std::array arr{ 13, 90, 99, 5, 40, 80 };
  std::sort(arr.begin(), arr.end(), greater);



  return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
