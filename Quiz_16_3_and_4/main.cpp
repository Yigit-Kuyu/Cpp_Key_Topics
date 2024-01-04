#include <iostream>
#include <vector>


std::vector<size_t> func(std::vector<int>& yck)
{
     if (yck.empty())
      {
      std::cout << "vector is empty";
      return {};
      }

      size_t min_index=0;
      size_t max_index=0;
      for(size_t i=0; i<yck.size(); ++i)
      {
         if (yck[i]<yck[min_index])
                min_index=i;
        else if (yck[i]>yck[max_index])
                max_index=i;
      }

      return {min_index, max_index};

}


int main()
{
    std::vector evens { 2, 4, 6, 8, 10, 12 }; // int vector
    const std::vector<double> evens_const { 1.2, 3.4, 5.6 }; // reminder: std::vector can't be constexpr
    std::vector <std::string_view> str {"Alex", "Brad", "Charles","Dave"};
    std::vector<int> single {12};
    std::vector<int> single_size(12);

    const std::vector <size_t> indexes=func(evens);

    for(auto i: indexes)
        std::cout << " Found indexes " << i << '\n';


    std::cout << "Hello world!" << std::endl;
    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz/
