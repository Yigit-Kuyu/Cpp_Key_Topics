#include <iostream>
#include "constant.h"

int main()
{
	std::cout << "How many students are in your class? ";
	int students{};
	std::cin >> students;


	if (students > constants::max_class_size)
		std::cout << "There are too many students in this class";
	else
		std::cout << "This class isn't too large";

	return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/chapter-7-summary-and-quiz/
