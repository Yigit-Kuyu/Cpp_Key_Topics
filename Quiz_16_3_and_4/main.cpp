#include <iostream>
#include <vector>
#include "Random.h"


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



std::vector<int> GetInput()
{
   std::vector<int> in{};
   int input;

   do
   {
   std::cout<< "get input: (-1 for exit): ";
   std::cin >> input;
   in.push_back(input);
    }
   while(input!=-1);

   return in;

};



namespace Wordlist
{

const std::vector<std::string> list_namee{"mystery", "broccoli" , "account"};
std::string chosen_word=list_namee[Random::get<std::size_t>(0, list_namee.size()-1)];

}

class Session
{
private:

    std::string chosen_word{};
    int input{};
    size_t num_trial{};
    char ch{};

public:
    Session(): chosen_word{Wordlist::chosen_word}
    {
    std::cout<< "chosen word in class: " << chosen_word << '\n';
    }

    void GetInput()
    {
    std::cout << "how many inputs: ";
    std::cin >> num_trial;

    for(size_t i=0; i<num_trial; ++i)
    {
    std::cout << "input (char): ";
    std::cin  >> ch ;
    if(std::isalpha(ch))
    {
    size_t found = chosen_word.find(ch);
    while (found != std::string::npos) {
        chosen_word.erase(found, 1);  // Erase 1 character at the found position
        found = chosen_word.find(ch);
    }
    }
    if(chosen_word.length()==0)
    {
        std::cout << "You win";
        return;
    }

    }
    std::cout << "You lose" << 'n';
    std::cout<< "chosen word in class: " << chosen_word << '\n';
    return;

    }


};


int main()
{
    std::vector<int> evens{};
    evens=GetInput();
    const std::vector <size_t> indexes=func(evens);

    for(auto i: indexes)
        std::cout << " Found indexes " << i << '\n';

    //############### Hangman Game #########################
    const std::string random_word{Wordlist::chosen_word};
    std::cout << "chose value in namespace: " << random_word<< '\n';

    Session S1;
    S1.GetInput();


    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz/
