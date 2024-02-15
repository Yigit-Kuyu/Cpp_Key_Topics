#include <iostream>
#include <string>
#include <string_view>


// An exception class is just a normal class that is designed specifically to be thrown as an exception.

class ArrayException
{
private:
	std::string m_error;

public:
	ArrayException(std::string_view error)
		: m_error{ error }
	{
	}

	const std::string& getError() const { return m_error; }
};

class IntArray
{
private:
	int m_data[3]{}; // assume array is length 3 for simplicity

public:
	IntArray() {}

	int getLength() const { return 3; }

	int& operator[](const int index)
	{
		if (index < 0 || index >= getLength())
			throw ArrayException{ "Invalid index" };

		return m_data[index];
	}

};

int main()
{
	IntArray array1;

	try
	{
		// Using the IntArray overloaded operator[]
		int value{ array1[5] }; // out of range subscript
	}
	catch (const ArrayException& exception)
	{
		std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
	}
}


// Output: An array exception occurred (invalid index)




// Related page:  https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/