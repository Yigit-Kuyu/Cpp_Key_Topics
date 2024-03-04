#include <iostream>
#include <memory> // for std::unique_ptr

/*

The defining characteristic of a smart pointer is that it manages a dynamically allocated resource,
and ensures the dynamically allocated object is properly cleaned up at the appropriate time (usually when the smart pointer goes out of scope).

*/


/*

std::unique_ptr is the C++11 replacement for std::auto_ptr.
It should be used to manage any dynamically allocated object that is not shared by multiple objects.

*/


/*  Note: make_unique

std::make_unique() (in C++14) should be preferred to create new std::unique_ptr. std::unique_ptr disables copy semantics.

*/



/* Note: Accessing the managed object

std::unique_ptr has an overloaded operator* and operator-> that can be used to return the resource being managed.
Operator* returns a reference to the managed resource, and operator-> returns a pointer.

*/


/* Note: Array and Vector

std::array or std::vector (or std::string) are almost always better choices than using std::unique_ptr with a fixed array, dynamic array, or C-style string.

*/


/* Note: Return by Function

In general, you should not return std::unique_ptr by pointer (ever) or reference (unless you have a specific compelling reason to) from a function.

*/


/* Note: Pass to Function

If you want the function to take ownership of the contents of the pointer, pass the std::unique_ptr by value.
Note that because copy semantics have been disabled, you’ll need to use std::move to actually pass the variable in.


Example:



void takeOwnership(std::unique_ptr<Resource> res) // This function takes ownership of the Resource, which isn't what we want
{
     if (res)
          std::cout << *res << '\n';
}

    auto ptr{ std::make_unique<Resource>() };

// takeOwnership(ptr); // This doesn't work, need to use move semantics
   takeOwnership(std::move(ptr)); // ok: use move semantics


*/


/* Note: Misusing

There are two easy ways to misuse std::unique_ptrs, both of which are easily avoided.

First, don’t let multiple classes manage the same resource.
For example:

Resource* res{ new Resource() };
std::unique_ptr<Resource> res1{ res };
std::unique_ptr<Resource> res2{ res };

// In the above code, the end result will be that both res1 and res2 will try to delete the Resource, which will lead to undefined behavior.


Second, don’t manually delete the resource out from underneath the std::unique_ptr.
For example:

Resource* res{ new Resource() };
std::unique_ptr<Resource> res1{ res };
delete res;

// In the above code, f you do, the std::unique_ptr will try to delete an already deleted resource, again leading to undefined behavior.


*/





#include <iostream>
#include <memory> // for std::unique_ptr
#include <utility> // for std::move

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    // std::unique_ptr<SomeObject> a = new SomeObject(...)
	//std::unique_ptr<Resource> res1{ new Resource{} }; // creates a std::unique_ptr named res1 that owns a new Resource object.
	// std::unique_ptr<SomeObject> a = std::make_unique(SomeObject(...))
	auto res1 = std::make_unique<Resource>(); // This does the same thing above "std::unique_ptr<Resource> res1{new Resource{}}"



	std::unique_ptr<Resource> res2{}; // Start as nullptr, holds no object
    // You don't use std::make_unique directly because std::make_unique is designed to create and own a new object,
    // and above unique_ptr has no object


	std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
	std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

	// res2 = res1; // Won't compile: copy assignment is disabled

	// res2 assumes ownership, res1 is set to null
	res2 = std::move(res1); // rather than copy semantic, use move semantics, because std::unique_ptr is designed with move semantics


	std::cout << "Ownership transferred\n";

	std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
	std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

	return 0;
} // Resource destroyed here when res2 goes out of scope




// Related page: https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
