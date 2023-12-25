#ifndef ADD_H
#define ADD_H

// The most conventional way to address the template
// is to put all your template code in a header (.h) file instead of a source (.cpp) file.

// Templates that are needed in multiple files should be defined in a header file, and then #included wherever needed.

template <typename T>
T addOne(T x) // function template definition
{
    return x + 1;
}

#endif
