#include <iostream>

// Command line arguments are optional string arguments that are passed by the operating system to the program when it is launched.

//  For example, to run the executable file “WordCount”, command line on a Unix-based OS would be:
// ./WordCount
// In order to pass command line arguments to WordCount:
// WordCount Myfile.txt
//  A program can have multiple command line arguments, separated by spaces:
// WordCount Myfile.txt Myotherfile.txt


/*
Using command line arguments:

To do that, we use a different form of main() than we’ve seen before. This new form of main() takes two arguments (named argc and argv by convention) as follows:
int main(int argc, char* argv[])
You will sometimes also see it written as:
int main(int argc, char** argv)

argc is an integer parameter containing a count of the number of arguments passed to the program (think: argc = argument count).
argc will always be at least 1, because the first argument is always the name of the program itself.

argv is where the actual argument values are stored (think: argv = argument values, though the proper name is “argument vectors”).
argv is just an array of char pointers.

*/


/*
To run this file on terminal:
First, compile file with g++ (you can find the version of g++ via g++ --version command), and generate output as yck_output:
g++ main.cpp -o yck_output
Second, run the file with desired command line arguments (abcd is a word and trial.txt is a text file found in the project file):
./yck_output trial.txt abcd

Output on terminal:
There are 3 arguments:
0 ./yck_output
1 trial.txt
2 abcd


*/


int main(int argc, char* argv[])
{
    std::cout << "There are " << argc << " arguments:\n";

    // Loop through each argument and print its number and value
    for (int count{ 0 }; count < argc; ++count)
    {
        std::cout << count << ' ' << argv[count] << '\n';
    }

    return 0;
}




// Related page: https://www.learncpp.com/cpp-tutorial/command-line-arguments/
