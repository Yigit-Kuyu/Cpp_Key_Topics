#include <iostream>
using namespace std;


// This is from my notes, not from learncpp.com

class YcK
{
   private:
        int length;
   public:
         YcK(): length{0} {}
   friend int printLength (YcK&); //friend function decleration
   void print_int(int); // function decleration
};

// You dont need scope resolution operator
int printLength (YcK& b) // Definition friend member function outside of the class.
{
    b.length +=10;
    return b.length;
}


void YcK::print_int(int i) // Definition member function outside of the class.
{
   cout << "given integer " << i << std::endl;
}


int main ()
{
   YcK b;
   cout << "Length of box: " <<printLength(b)<<endl;
   return 0;
}


