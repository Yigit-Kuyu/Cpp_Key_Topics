#include <iostream>
#include "constant.h"



double calculateHeight(double initialHeight)
{

    int seconds{0};
    while(true)
    {

    double distanceFallen=myConstants::gravity * seconds * seconds / 2 ;
    double heightNow=initialHeight - distanceFallen;

    if (heightNow<0)
        return heightNow;
    else
        ++seconds;


    }


}


void calculateAndPrintHeight(double initialHeight)
{
    std::cout << " the ball is at height: " << calculateHeight(initialHeight) << '\n';
}




int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight {};
    std::cin >> initialHeight;

    calculateAndPrintHeight(initialHeight);

    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/
