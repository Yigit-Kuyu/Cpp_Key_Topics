#include <iostream>
#include <cassert>
#include <cstddef>

/*

Like constructors, destructors have specific naming rules:

The destructor must have the same name as the class, preceded by a tilde (~).
The destructor can not take arguments.
The destructor has no return type.
A class can only have a single destructor.

*/


/*

Generally you should not call a destructor explicitly (as it will be called automatically when the object is destroyed),
since there are rarely cases where you’d want to clean up an object more than once.
However, destructors may safely call other member functions since the object isn’t destroyed until after the destructor executes.

*/



class IntArray
{
private:
	int* m_array{};
	int m_length{};

public:
	IntArray(int length) // constructor
	{
		assert(length > 0);

		m_array = new int[static_cast<std::size_t>(length)]{};
		m_length = length;
	}

	~IntArray() // destructor
	{
		// Dynamically delete the array we allocated earlier
		delete[] m_array;
	}

	void setValue(int index, int value) { m_array[index] = value; }
	int getValue(int index) { return m_array[index]; }

	int getLength() { return m_length; }
};

int main()
{
	IntArray ar ( 10 ); // allocate 10 integers
	for (int count{ 0 }; count < ar.getLength(); ++count)
		ar.setValue(count, count+1);

	std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';

	return 0;
} // ar is destroyed here, so the ~IntArray() destructor function is called here



// Related page: https://www.learncpp.com/cpp-tutorial/destructors/


