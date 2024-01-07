#include <iostream>
#include <array>
#include <string_view>
#include "Random.h"



namespace Potion
{
    enum Type
        {
         tp0,
         tp1,
         tp2
         };


constexpr std::array<int, 3> pot_costs{ 20, 30, 12};
constexpr std::array<std::string_view, 3> pot_names{"tp0", "tp1", "tp2"};

}



void shop()
{

/*

for (auto i: Potion::Type) // Error: you cannot for(auto i:...) style with enum, use standart for loop
{
std::cout<< "index: "<< static_cast<int>(i) << "names: " <<  Potion::pot_names[static_cast<size_t>(i)] << "cost: " << Potion::pot_costs[static_cast<size_t>(i)] <<'\n';
}
*/

for (size_t i{0};  i<Potion::pot_names.size(); ++i) // standart for loop
{
std::cout<< "index: "<< i << " names: " <<  Potion::pot_names[i] << " cost: " << Potion::pot_costs[i] <<'\n';
}


}


class Player {

private:

std::array<std::string_view,3> name {};
int potion_inventory{};
std::array<int,3> gold{};
std::string_view intro_text{};

public:
     explicit Player(int m): gold{1,2,3},name {"aa","bb", "cc"},intro_text{"welcome"}, potion_inventory{3}
     {

     const std::string chosen_name{name[m]};
     const int chosen_gold{gold[m]};

     std::cout<< "name: " <<  chosen_name << " gold: " << chosen_gold <<'\n';


     }

     int Getgold(int m) const { return gold[m]; }
     std::string_view Getname (int m) const { return name[m];}


};


int main()
{
    shop();

    int m= Random::get(0, 3);
    Player p(m);
    std::cout << "gold: " << p.Getgold(m) << " name: " << p.Getname(m) << '\n';

    return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz/
