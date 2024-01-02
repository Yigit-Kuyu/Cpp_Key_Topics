#include <iostream>

class Fraction
{
public:
    int numerator{ 0 };
    int denominator{ 1 };

Fraction(int x, int y)
: numerator{x}, denominator{y} {}

Fraction() {}


void getFraction()
{

    std::cout << "Enter a value for numerator: ";
    std::cin >> numerator;
    std::cout << "Enter a value for denominator: ";
    std::cin >> denominator;
    std::cout << '\n';

}


Fraction multiply(const Fraction& f1) const
{
    return Fraction{ f1.numerator * numerator, f1.denominator * denominator };
}


void printFraction() const
{
    std::cout << numerator << '/' << denominator << '\n';
}



};


int main()
{

    Fraction f1{};
    Fraction f2{};
    f1.getFraction();
    f2.getFraction();

    std::cout << "Your fractions multiplied together: ";
    Fraction yck_result=f2.multiply(f1);
    yck_result.printFraction();


    return 0;
}





// Related page: https://www.learncpp.com/cpp-tutorial/chapter-14-summary-and-quiz/
