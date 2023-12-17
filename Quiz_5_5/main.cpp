#include <iostream>
#include <string> // For std::string and std::getline




std::string getName()
{

std::string name;
std::cout << "Input name: \n";
std::getline(std::cin >> std::ws, name);
return name;

}


int getAge()
{

int age;
std::cout << "Input age: \n";
std::cin>> age;
return age;

}

void compare(std::string name1, int age1, std::string name2, int age2)
{

// c ? x : y	If conditional c is true then evaluate x, otherwise evaluate y

std::string old= (age1 > age2) ? name1: name2;
int old_age=(age1 > age2) ? age1: age2;

std::cout << "older person " << old << " age: " << old_age << std::endl;

}



int main()
{

    std::string name1{getName()};
    int age1 {getAge()};


    std::cout << "Name: " << name1 << " Age: " << age1 << std::endl;

    std::string name2{getName()};
    int age2 {getAge()};

    std::cout << "Name: " << name2 << " Age: " << age2 << std::endl;


    compare(name1, age1, name2,age2);


    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/chapter-5-summary-and-quiz/

