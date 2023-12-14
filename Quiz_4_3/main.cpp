#include <iostream>
#include <math.h>

using namespace std;


int take_height() {

    int h;
    cout<<"Please input in m:" << endl;
    cin>> h;
    return h;

}


int calculation()
{
const double gravity = 3.14;
int h=take_height();
int t=0;
int fall;


   while(h>0)

   {
     t+=1;
     fall=gravity*pow(t,2)/2.0;
     h=h-fall;
     cout<<" At second "<< t << "the ball is at height: " << h << endl;



   }

}


int main()
{



   calculation();



    return 0;
}



// Related topic: https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/
