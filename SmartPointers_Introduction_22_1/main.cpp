#include <iostream>





// A Smart pointer is a composition class that is designed to manage dynamically allocated memory
// and ensure that memory gets deleted when the smart pointer object goes out of scope.


/* Move semantics:

Move semantics mean a class will transfer ownership of the object rather than making a copy.
This is done primarily via the move constructor and move assignment operator.

The goal of the move constructor and move assignment is to move ownership of the resources
from one object to another (which is typically much less expensive than making a copy).


*/


/*  Copy semantics:

Copy semantics allow our classes to be copied. This is done primarily via the copy constructor and copy assignment operator.

Copy constructors are used to initialize a class by making a copy of an object of the same class.
Copy assignment is used to copy one class object to another existing class object.
By default, C++ will provide a copy constructor and copy assignment operator if one is not explicitly provided.

*/



/* r-value

An r-value reference is a reference that is designed to be initialized with an r-value.
An r-value reference is created using a double ampersand.


*/


/* l-value

If we construct an object or do an assignment where the argument is an l-value, the only thing we can reasonably do is copy the l-valu


*/



template<typename T>
class Auto_ptr4
{
	T* m_ptr {};
public:
	Auto_ptr4(T* ptr = nullptr)
		: m_ptr { ptr }
	{
	}

	~Auto_ptr4()
	{
		delete m_ptr;
	}

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4(const Auto_ptr4& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4(Auto_ptr4&& a) noexcept
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
	}

	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4& operator=(const Auto_ptr4& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4& operator=(Auto_ptr4&& a) noexcept
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr4<Resource> generateResource()
{
	Auto_ptr4<Resource> res{new Resource};
	return res; // this return value will invoke the move constructor
}

int main()
{
	Auto_ptr4<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the move assignment

	return 0;
}



// Related lesson: https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/
//                 https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/
