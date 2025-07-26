

#include "Base.hpp"

/* runtime type identification (RTTI) -> dynamic cast

In C++, dynamic_cast is a cast operator that converts data from one type to another type at runtime. 
It is mainly used in inherited class hierarchies for safely casting the base class pointer or 
reference to derived class (called downcasting). 
To work with dynamic_cast, there must be one virtual function in the base class.

https://www.geeksforgeeks.org/cpp/dynamic-_cast-in-cpp/ 

*/
int main(void)
{
	Base *ptr = NULL;

	ptr = Base::generate();
	
	Base::identify(ptr); //ptr
	Base::identify(*ptr); //ref


	if (ptr != NULL)
		delete ptr;
}