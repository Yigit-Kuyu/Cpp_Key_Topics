#include <iostream>
#include <vector>

/*
In programming, a stack is a container data type where the insertion and removal of elements occurs in a LIFO manner.
The order in which items are added to and removed from a stack can be described as last-in, first-out (LIFO).
*/


void printStack(const std::vector<int>& stack)
{
	if (stack.empty()) // if stack.size == 0
		std::cout << "Empty";

	for (auto element : stack)
		std::cout << element << ' ';

	 // length is the number of elements in the vector, which in this case, is the number of elements on our stack.
	std::cout << "\tCapacity: " << stack.capacity() << "  Length " << stack.size() << "\n"; // \t is a tab character, to help align the text
}

int main()
{
	std::vector<int> stack{}; // empty stack

	printStack(stack);
    // push_back() (and emplace_back()) will increment the length of the vector,
    // and will cause a reallocation to occur if the capacity is not sufficient to insert the value.
	stack.push_back(1); // push_back() pushes an element on the stack (add the element to the last of the vector)
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	std::cout << "Last element: " << stack.back() << '\n'; // back() returns the last element

	stack.pop_back(); // pop_back() pops an element off the stack (remove the element from the last of the vector)
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

    std::cout << '\n';
	// ###############  Changing capacity of vector:     ##########################
	std::vector<int> stack1(3); // set vector's capacity to 3
	stack1.push_back(10); // add 10 to the last of the vector
	for (auto element1 : stack1)
	    // push_back changes the length of the vector, in this case from 3 to 4
		std::cout << "the stack1 vector: "<<element1 << '\n'; // Problem: 10 added after {0,0,0}, leading to {0,0,0,10}
    // To solve above problem:
    std::vector<int> stack2{};
    stack2.reserve(6); // reserve space for 6 elements (but do not change length)
    stack2.push_back(10); // add 100 to the last of the vector
    for (auto element2 : stack2)
	    // push_back changes the length of the vector, in this case from 3 to 4
		std::cout << "\nthe stack2 vector: "<<element2 << '\n'; // Problem: 10 added after {0,0,0}, leading to {0,0,0,10}



	return 0;
}



// Related page: https://www.learncpp.com/cpp-tutorial/stdvector-and-stack-behavior/
