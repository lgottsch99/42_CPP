
#include "A_Animal.hpp"
#include <iostream>

//Con- /Destructors -------------------------
//default
A_Animal::A_Animal(void):
type("")
{
	std::cout << "(A_Animal) Default (void) constructor called\n";
}

//copy construct
A_Animal::A_Animal(const A_Animal& other)
{
	std::cout << "(A_Animal) Copy constructor called\n";
	type = other.type;
}

//copy assignment
A_Animal &A_Animal::operator=(const A_Animal& other)
{
	std::cout << "(A_Animal) Copy assignment operator called\n";
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

//destructor
A_Animal::~A_Animal()
{
	std::cout << "(A_Animal) Destructor called\n";
}


// void	A_Animal::makeSound(void) const
// {
// 	std::cout << "~ (A_Animal) making some random sound ~\n";
// }

const std::string& A_Animal::getType(void) const
{
	return(type);
}