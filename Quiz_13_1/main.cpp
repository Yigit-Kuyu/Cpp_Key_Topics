#include <iostream>


struct Monsters
{

std::string name{};
int health{};

};


void printMonster(Monsters& a)
{

std::cout << "name: "<< a.name << " health: " << a.health << std::endl;

}


int main()
{

   Monsters ogre={"og",90};
   Monsters slime={"sl",80};

   printMonster(ogre);
   printMonster(slime);





    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/chapter-13-summary-and-quiz/
