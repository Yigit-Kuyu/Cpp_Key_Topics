#include <iostream>


// This code does not work. It is used for only explanation.


/*
Exception handling is best used when all of the following are true:

The error being handled is likely to occur only infrequently.
The error is serious and execution could not continue otherwise.
The error cannot be handled at the place where it occurs.
*/


int main()
{


try
{

    /*
    What happens if WriteFile() fails and throws a FileException? At this point, we’ve already opened the file,
    and now control flow jumps to the FileException handler, which prints an error and exits. Note that the file was never closed!
    */
    openFile(filename);
    writeFile(filename, data);
    closeFile(filename); // wrong location, should be removed
}
catch (const FileException& exception)
{
    std::cerr << "Failed to write to file: " << exception.what() << '\n';
}

 closeFile(filename); //   correct location

    return 0;
}


// Related page: https://www.learncpp.com/cpp-tutorial/exception-dangers-and-downsides/
