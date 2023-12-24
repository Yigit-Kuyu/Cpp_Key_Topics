#include <iostream>
#include "Random.h"  // https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/#RandomH


bool PlayAgain()
{
char ch {};
std::cout << " Would you like to play again (y/n) " << std::endl;
std::cin >> ch;

if (ch=='y') {return 1;}
else {return 0;}


}



void calculateGuess()
{

constexpr int max_guess{7}; // the user has this many guesses
int i{0};
int mt{ Random::get(1,100) }; // this is the number the user needs to guess
int num{};


do{
    do {
    std::cout << " Please input valid a number (1-100): " << std::endl;
    std::cin >> num;
        }
    while(num<0 || num>100);




for(int i=0; i<max_guess; ++i)
   {

        if(num>mt)
                {
                std::cout << "go lower write new one : " << std::endl;
                std::cin >> num;
                ++i;
                } else if (num<mt)
                {
                     std::cout << "go upper write new one : " << std::endl;
                     std::cin >> num;
                     ++i;

                }

    } // end for



} // end do
while(PlayAgain());



}




int main()
{


    calculateGuess();
    return 0;


}




// Related page: https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/
