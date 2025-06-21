

#include "Dog.hpp"
#include <iostream>

//Con- /Destructors -------------------------
//default
Dog::Dog(void): 
Animal()
{
	std::cout << "(Dog) Default (void) constructor called\n";
	type = "Dog";
}

//copy construct
Dog::Dog(const Dog& other):
Animal()
{
	std::cout << "(Dog) Copy constructor called\n";
	type = other.type;
}

//copy assignment
Dog &Dog::operator=(const Dog& other)
{
	std::cout << "(Dog) Copy assignment operator called\n";
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

//destructor
Dog::~Dog()
{
	std::cout << "(Dog) Destructor called\n";
}


void	Dog::makeSound(void) const
{
	std::cout << "~ (Dog) woof! ~\n";
}