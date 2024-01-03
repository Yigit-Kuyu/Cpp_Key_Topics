#include <iostream>
#include <vector>

// If we pass a std::vector by value, an expensive copy will be made.
// Therefore, we typically pass std::vector by (const) reference to avoid such copies.



void passByRef(const std::vector<int>& arr) // we must explicitly specify <int> here
{
    std::cout << "passByRef: " <<arr[0] << '\n';
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

    std::vector dbl{ 1.1, 2.2, 3.3 };
    //passByRef(dbl); // compile error: std::vector<double> is not convertible to std::vector<int>


    passByRef_withTemplate(primes); // ok: compiler will instantiate passByRef(const std::vector<int>&)
    passByRef_withTemplate(dbl);    // ok: compiler will instantiate passByRef(const std::vector<double>&)


    return 0;
}



// Related page:https://www.learncpp.com/cpp-tutorial/passing-and-returning-stdvector-and-an-introduction-to-move-semantics/
