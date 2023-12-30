#include <iostream>

template <typename T>
struct Triad
{
T x{};
T y{};
T z{};
};

// If using C++17, we need to provide a "deduction guide" (not required in C++20)
// A Triad with three arguments of the same type should deduce to a Triad<T>
template<typename T>
Triad(T,T,T)->Triad<T>;

template<typename T>
void print(Triad<T>& tr)
{
std::cout << "x "<< tr.x << " y " << tr.y << " z " << tr.z << std::endl;

}

int main()
{
	Triad t1{ 1, 2, 3 };
	// If you dont use deduction guide, use: (comment out line 13,14, 25)
	// Triad<int> t1{ 1, 2, 3 }

	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 };
	// If you dont use deduction guide, use:(comment out line 13,14, 31)
	// Triad<double> t2{ 1.2, 3.4, 5.6 };

	print(t2);

	return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/chapter-13-summary-and-quiz/
