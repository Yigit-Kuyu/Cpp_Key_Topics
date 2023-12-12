#include <iostream>

using namespace std;

int readNumber(int x, int y)
{
    return x + y;
}

void writeAnswer(int t)
{
    cout<< t << endl;
}

int main()
{

    int x,y,total;
    cin >> x;
    cin >> y;
    total=x+y;

    writeAnswer(total);
    return 0;
}

// Related link: https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/
