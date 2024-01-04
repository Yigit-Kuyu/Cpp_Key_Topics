#include <iostream>
#include <vector>
#include <string_view>





int main()
{
    std::vector evens { 2, 4, 6, 8, 10, 12 };
    const std::vector<double> evens_const { 1.2, 3.4, 5.6 }; // reminder: std::vector can't be constexpr
    std::vector <std::string_view> str {"Alex", "Brad", "Charles","Dave"};
    std::vector<int> single {12};
    std::vector<int> single_size(12);


    std::cout << "Hello world!" << std::endl;
    return 0;
}





// Related page: https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz/
