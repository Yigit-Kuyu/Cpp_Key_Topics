#include <iostream>




enum MonsterType // this enum is defined in the global namespace
{
    Dragon,
    Goblin,
    Ogre,
    max_monster_types
};



class Monster {

public:
using Type=MonsterType;
Monster(const Type& x, const std::string& y, const std::string& z, const int n)
      :m_mt{x},m_name{y},m_roar{z},m_num_hit_points{n} {}

private:

MonsterType m_mt{};
std::string m_name{};
std::string m_roar{};
int m_num_hit_points{};

public:

std::string getTypeString()
{
   switch (m_mt) {
        case Dragon: return "Dragon";
        case Goblin: return "Goblin";
        case Ogre: return "Ogre";
        default: return "Unknown";
                }
}


void print()
{
std::cout << getTypeString() << " named " << m_name << " says " << m_roar << " and has " << m_num_hit_points << " hit points." << std::endl;
}

};



int main()
{
	Monster OgreMonster{Ogre, "Bones", "*rattle*", 4 };
    OgreMonster.print();


	return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/chapter-15-summary-and-quiz/
