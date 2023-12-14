#include <iostream>

using namespace std;



double get_Value()
{

double x;
cout << "Please write an input" << endl;
cin>> x;
return x;

}


char get_Symbol()

{

char x;
cout << "Please write an input as symbol" << endl;
cin>> x;
return x;

}



int calculate_Result(float x, float y, char s)
{

 if(s!='+' || s!='-' || s!='*' || s!='/') {

        cout<< "invalid input";
        return 0;

    }
    else
    {
        double result;

        if(s=='-') {
            cout<< 'result: ' << x-y << endl;
            return 0;
                   }

    }


}



int main()
{
    double a {get_Value()};
    double b {get_Value()};
    char c {get_Symbol()};



    calculate_Result(a,b,c);


    return 0;
}

// Related topic: https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/
