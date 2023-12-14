#include <plog/Log.h> // Step 1: include the logger headers
#include <plog/Initializers/RollingFileInitializer.h>
#include <iostream>

int getUserInput()
{
	PLOGD << "getUserInput() called"; // PLOGD is defined by the plog library
    int number{3};
	std::cout << " a number: " << 3 << std::endl;

	return number;
}

int getNumberInput()
{
	PLOGD << "getNumberInput() called"; // PLOGD is defined by the plog library
    int number{4};
	std::cout << " a number: " << 4 << std::endl;

	return number;
}

int main()
{
	plog::init(plog::debug, "Logfile.txt"); // Step 2: initialize the logger

	PLOGD << "main() called"; // Step 3: Output to the log as if you were writing to the console

	int x{ getUserInput() };
	int y{ getNumberInput() };
	std::cout << "You entered: " << x << '\n';

	return 0;
}


// Related lesson: https://www.learncpp.com/cpp-tutorial/more-debugging-tactics/
// https://www.learncpp.com/cpp-tutorial/a3-using-libraries-with-codeblocks/
