
#include "Base.hpp"


//destructor
Base::~Base()
{
	std::cout << "(Base) Destructor\n";
}

// Methods ------------------------------

/* It randomly instantiates A, B, or C and returns the instance as a Base pointer. 
Feel free to use anything you like for the random choice implementation.
*/
Base*	Base::generate(void)
{
	Base *ptr = NULL;

	//random choice
	std::srand(std::time(NULL)); //seed for rand (aka setting internal algo params for random numbers), otherwise rand always the same
	int i = std::rand() % 3;
	std::cout << "random int is: " << i << "\n";

	switch (i)
	{
		case 0:
			ptr = new A;
			break;
		case 1:
			ptr = new B;
			break;
		case 2:
			ptr = new C;
			break;
	}
	return (ptr);
}


/* 
It prints the actual type of the object pointed to by p: "A", "B", or "C".
*/
void		Base::identify(Base* p) //ptr
{ //use dynamic cast and check which one succeedes!
	A* Aptr = NULL;
	B* Bptr = NULL;
	C* Cptr = NULL;

	Aptr = dynamic_cast<A*>(p);
	if (Aptr != NULL)
		std::cout << "Pointer actual type is: A\n";
	else
	{
		Bptr = dynamic_cast<B*>(p);
		if (Bptr != NULL)
			std::cout << "Pointer actual type is: B\n";
		else
		{
			Cptr = dynamic_cast<C*>(p);
			if (Cptr != NULL)
				std::cout << "Pointer actual type is: C\n";
			else
				std::cout << "Cannot identify ptr type...\n";
		}
	}
	Aptr = NULL;
	Bptr = NULL;
	Cptr = NULL;
}

/* 
It prints the actual type of the object referenced by p: "A", "B", or "C". 
Using a pointer inside this function is forbidden.
*/
void		Base::identify(Base& p) //ref
{
	//A
	try
	{
		Base &a = dynamic_cast<A&>(p);
		std::cout << "Reference actual type is: A\n";
		(void)a;
		return;
	}
	catch(const std::exception& e)
	{
	}
	//B
	try
	{
		Base &a = dynamic_cast<B&>(p);
		std::cout << "Reference actual type is: B\n";
		(void)a;
		return;

	}
	catch(const std::exception& e)
	{
	}
	//C
	try
	{
		Base &a = dynamic_cast<C&>(p);
		std::cout << "Reference actual type is: C\n";
		(void)a;
		return;

	}
	catch(const std::exception& e)
	{
	}
}
