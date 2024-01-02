#include <iostream>
#include <cmath> // for sqrt

class Point2d
{
private:

double m_x{0};
double m_y{0};

public:
        Point2d(){}

       Point2d(double x, double y)
       :m_x{x}, m_y{y} {}

void print()
{

std::cout << " x variable " << m_x << " y variable " << m_y << std::endl;

}

double distanceTo(Point2d& p_2d)

{

return std::sqrt((m_x - p_2d.m_x)*(m_x - p_2d.m_y) + (m_y - p_2d.m_y)*(m_y - p_2d.m_y));
}


};


int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/chapter-14-summary-and-quiz/
