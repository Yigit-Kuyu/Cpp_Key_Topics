#include <iostream>
#include <vector>

// If we pass a std::vector by value, an expensive copy will be made.
// Therefore, we typically pass std::vector by (const) reference to avoid such copies.



void passByRef(const std::vector<int>& arr) // we must explicitly specify <int> here
{
    std::cout << "passByRef: " <<arr[3] << '\n';

    // If "arr" is a 2-element array, this will issue undefined behavior.
    // One option here is to assert on arr.size(), which will catch such errors when run in a debug build configuration.
    // Because std::vector::size() is a non-constexpr function, we can only do a runtime assert here.
    // A better option is to avoid using std::vector in cases where you need to assert on array length. Using a type that
    // supports constexpr arrays (e.g. std::array) is probably a better choice, as you can static_assert on the length of a constexpr array.

}

template <typename T>
void passByRef_withTemplate(const std::vector<T>& arr)
{
    std::cout <<  "passByRef_withTemplate: " << arr[0] << '\n';
}


int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 };
    passByRef(primes);  // ok: this is a std::vector<int>

    std::vector dbl{ 1.1, 2.2, 3.3, 4.4 };
    //passByRef(dbl); // compile error: std::vector<double> is not convertible to std::vector<int>


    passByRef_withTemplate(primes); // ok: compiler will instantiate passByRef_withTemplate(const std::vector<int>&)
    passByRef_withTemplate(dbl);    // ok: compiler will instantiate passByRef_withTemplate(const std::vector<double>&)


    return 0;
}



// Related page:https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdvector-and-an-introduction-to-move-semantics/
