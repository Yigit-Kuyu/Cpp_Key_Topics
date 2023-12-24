#include <cassert>
#include <iostream>
#include <cmath>

bool isPrime(int x)
{
    if (x<0)
       return 1;

    for(int i{2}; i<x; ++i)
    {
         if(x%i==0)
            return 1;

    }

}



bool isComposite(int x)
{
    if (x<0)
       return 1;

    for(int i{2}; i<x; ++i)
    {
         if(x%i==0 && i<=std::sqrt(x))
            return 1;

    }

}

int main()
{

    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));


    assert(!isComposite(0));
    assert(!isComposite(8));
    assert(!isComposite(2));
    assert(!isComposite(3));


    std::cout << "Success!\n";

    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/
