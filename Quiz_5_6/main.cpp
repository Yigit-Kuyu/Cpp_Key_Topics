#include <iostream>

// Write the function getQuantityPhrase() here

std::string getQuantityPhrase(int num)
{
std::string val;

if(num==0)
{
val="no";
}
else if(num==1)
{
val="a single";
}
else if(num==2)
{
val=" a couple of";
}
else if(num==3)
{
val="a few";
}
else {

val="many";
}

return val;

}


// Write the function getApplesPluralized() here
constexpr std::string_view getApplesPluralized(int num)
{
return (num == 1) ? "apple" : "apples";



}



int main()
{
    std::cout << "Mary has " << getQuantityPhrase(3) << " " << getApplesPluralized(3) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << " " << getApplesPluralized(numApples) << ".\n";

    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/chapter-5-summary-a
