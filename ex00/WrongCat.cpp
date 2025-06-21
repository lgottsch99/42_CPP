
#include "WrongCat.hpp"
#include <iostream>

//Con- /Destructors -------------------------
//default
WrongCat::WrongCat(void): 
WrongAnimal()
{
	std::cout << "(WrongCat) Default (void) constructor called\n";
	type = "WrongCat";
}

//copy construct
WrongCat::WrongCat(const WrongCat& other):
WrongAnimal()
{
	std::cout << "(WrongCat) Copy constructor called\n";
	type = other.type;
}

//copy assignment
WrongCat &WrongCat::operator=(const WrongCat& other)
{
	std::cout << "(WrongCat) Copy assignment operator called\n";
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

//destructor
WrongCat::~WrongCat()
{
	std::cout << "(WrongCat) Destructor called\n";
}


// void	WrongCat::makeSound(void) const
// {
// 	std::cout << "~ (WrongCat) miau! ~\n";
// }