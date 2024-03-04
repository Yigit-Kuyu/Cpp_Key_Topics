#include <iostream>
#include <memory> // for std::shared_ptr


/*

Unlike std::unique_ptr, which is designed to singly own and manage a resource,
std::shared_ptr is meant to solve the case where you need multiple smart pointers co-owning a resource.
This means that it is fine to have multiple std::shared_ptr pointing to the same resource.

As long as at least one std::shared_ptr is pointing to the resource,
the resource will not be deallocated, even if individual std::shared_ptr are destroyed.
As soon as the last std::shared_ptr managing the resource goes out of scope, the resource will be deallocated.

Like std::unique_ptr, std::shared_ptr lives in the <memory> header.


 */


 /*  Note: Array


In C++17 and earlier, std::shared_ptr does not have proper support for managing arrays,
and should not be used to manage a C-style array. As of C++20, std::shared_ptr does have support for arrays.

 */

 /* Note: Summary

 std::shared_ptr is designed for the case where you need multiple smart pointers co-managing the same resource.
 The resource will be deallocated when the last std::shared_ptr managing the resource is destroyed.

 */



class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	Resource* res { new Resource };
	std::shared_ptr<Resource> ptr1 { res };
	{
		//std::shared_ptr<Resource> ptr2 { ptr1 }; // better usage than below
		std::shared_ptr<Resource> ptr2 { res }; // create ptr2 directly from res (instead of ptr1), resulting in crash (aborted).

		std::cout << "Killing std::shared_ptr shared pointer\n";
	} // ptr2 goes out of scope here, and the allocated Resource is destroyed

	std::cout << "Killing std::shared_ptr shared pointer\n";


	/*

	Even though they’re both pointing to the same Resource, they aren’t aware of each other.
	When ptr2 goes out of scope, it thinks it’s the only owner of the Resource, and deallocates it.
    When ptr1 later goes out of the scope, it thinks the same thing, and tries to delete the Resource again. Then bad things happen (crash).

    If you use "td::shared_ptr<Resource> ptr2 { ptr1 }; ",  when ptr2 goes out of scope, the Resource is not deallocated,
    because ptr1 is still pointing at the Resource. So, there will be no crash.


	*/





	// ############ std::make_shared ##################
	// The reasons for using std::make_shared() are the same as std::make_unique() -- std::make_shared() is simpler and safer.


    // Same as above code, allocate a Resource object and have it owned by std::shared_ptr
	auto ptr11 { std::make_shared<Resource>() };
	{
		auto ptr22 { ptr11 }; // create ptr22 using copy of ptr11, at this time they shares the same resource.

		std::cout << "Killing std::make_shared shared pointer\n";
	} // ptr22 goes out of scope here, but nothing happens

	std::cout << "Killing std::make_shared shared pointer\n";


	return 0;
} // ptr11 goes out of scope here, and the allocated Resource is destroyed again






// Related page: https://www.learncpp.com/cpp-tutorial/stdshared_ptr/
