
#include "WrongAnimal.hpp"
#include <iostream>

//Con- /Destructors -------------------------
//default
WrongAnimal::WrongAnimal(void):
type("")
{
	std::cout << "(WrongAnimal) Default (void) constructor called\n";
}

//copy construct
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "(WrongAnimal) Copy constructor called\n";
	type = other.type;
}

//copy assignment
WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "(WrongAnimal) Copy assignment operator called\n";
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

//destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "(WrongAnimal) Destructor called\n";
}


void	WrongAnimal::makeSound(void) const
{
	std::cout << "~ (WrongAnimal) making some random sound ~\n";
}

const std::string& WrongAnimal::getType(void) const
{
	return(type);
}