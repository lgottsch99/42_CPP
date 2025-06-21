
#include "Cat.hpp"
#include <iostream>

//Con- /Destructors -------------------------
//default
Cat::Cat(void): 
Animal()
{
	std::cout << "(Cat) Default (void) constructor called\n";
	type = "Cat";
}

//copy construct
Cat::Cat(const Cat& other):
Animal()
{
	std::cout << "(Cat) Copy constructor called\n";
	type = other.type;
}

//copy assignment
Cat &Cat::operator=(const Cat& other)
{
	std::cout << "(Cat) Copy assignment operator called\n";
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

//destructor
Cat::~Cat()
{
	std::cout << "(Cat) Destructor called\n";
}


void	Cat::makeSound(void) const
{
	std::cout << "~ (Cat) miau! ~\n";
}