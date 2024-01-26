#include <iostream>
#include <exception> // for std::exception

class Fraction {
private:
       int num;
       int denum;
public:
       Fraction(int n, int d): num{n}, denum{d}
       {
       if (denum==0)
           throw 1;
       }

};


int main()
{

    std::cout << "Input denum and enum" << std::endl;
    int denum, enumm;

    std::cin >> denum >> enumm ;

   try{
   Fraction f(enumm,denum);
   }
   catch(int)
   {
    std::cerr << "denum should not be zero" << std::endl;
   }
   catch(const std::exception& e) //  If the Fraction is invalid
   {
   std::cerr << e.what() << '\n';
   }


    return 0;
}
