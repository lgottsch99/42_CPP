
#include "Animal.hpp"
#include <iostream>

//Con- /Destructors -------------------------
//default
Animal::Animal(void):
type("")
{
	std::cout << "(Animal) Default (void) constructor called\n";
}

//copy construct
Animal::Animal(const Animal& other)
{
	std::cout << "(Animal) Copy constructor called\n";
	type = other.type;
}

//copy assignment
Animal &Animal::operator=(const Animal& other)
{
	std::cout << "(Animal) Copy assignment operator called\n";
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

//destructor
Animal::~Animal()
{
	std::cout << "(Animal) Destructor called\n";
}


void	Animal::makeSound(void) const
{
	std::cout << "~ (Animal) making some random sound ~\n";
}

const std::string& Animal::getType(void) const
{
	return(type);
}