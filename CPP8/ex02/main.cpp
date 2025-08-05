
#include "MutantStack.hpp"
#include <list>

/*

https://www.geeksforgeeks.org/cpp/stack-in-cpp-stl/
https://en.cppreference.com/w/cpp/container/stack.html 
https://www.geeksforgeeks.org/cpp/container-adapter-in-cpp/

Stack = LIFO (last in first out) = container ADAPTER (= wrapper that restricts access)

The underlying container may be any of the standard container class templates or some 
other specifically designed container class. 
The container shall support the following operations:
empty
size
top
push
pop


*/

int main(void)
{
	//subject main ----
	MutantStack<int> mstack;
	std::cout << "\nMUTANT STACK TEST ----------\n\n\n";

	if (mstack.empty())
		std::cout << "mstack is empty\n";

	std::cout << "pushing to mstack..\n";
	mstack.push(5);
	mstack.push(17);

	if (!mstack.empty())
		std::cout << "mstack not empty\n";

	std::cout << "top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	
	//[...] 
	mstack.push(0);

	std::cout << "\nprinting stack after adding: \n";
	MutantStack<int>::iterator it = mstack.begin(); 
	MutantStack<int>::iterator ite = mstack.end();
	++it; //just testing if ++/-- is working and doesnt throw errors
	--it;
	while (it != ite) 
	{
		std::cout << *it << std::endl;
		++it; 
	}
	std::cout << "size: " << mstack.size() << std::endl;

	std::stack<int> s(mstack); //?? -> since mstack inherits from stack it can be copy constructed with stack, no issue
	std::cout << "size std::stack<int> s(mstack): " << s.size() << std::endl;



	// list test ----------------
	std::list<int> list;
	std::cout << "\n\nLIST TEST ----------\n\n\n";

	if (list.empty())
	std::cout << "list is empty\n";

	std::cout << "pushing to list..\n";
	list.push_back(5);
	list.push_back(17);

	if (!list.empty())
		std::cout << "list not empty\n";

	std::cout << "top: " << list.back() << std::endl;

	list.pop_back();

	std::cout << "size: " << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);

	//[...] 
	list.push_back(0);

	std::cout << "\nprinting stack after adding: \n";
	std::list<int>::iterator lit = list.begin(); 
	std::list<int>::iterator lite = list.end();
	++lit;
	--lit;
	while (lit != lite) 
	{
		std::cout << *lit << std::endl;
		++lit; 
	}
	std::cout << "size: " << list.size() << std::endl;

	return 0;
	
}
