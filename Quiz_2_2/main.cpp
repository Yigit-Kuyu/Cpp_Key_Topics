#include <iostream>


using namespace std;


void writeAnswer(int );
int readNumber(int , int );

int main()
{

    int x,y,total;
    cin >> x;
    cin >> y;
    total=x+y;

    writeAnswer(total);
    return 0;
}
