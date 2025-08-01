
#include "MutantStack.hpp"

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
back
push_back
pop_back


*/

int main(void)
{
	MutantStack<int> mstack;
}