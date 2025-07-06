
#include "AMateria.hpp"
#include <iostream>

//default constructor
AMateria::AMateria(std::string const & type)
{
	std::cout << "(AMateria) default constructor called";
	this->type = type;
}

//copy construct
AMateria::AMateria(const AMateria& other)
{
	std::cout << "(AMateria) copy constructor called";
	this->type = other.type;
}

//copy assignment
AMateria &AMateria::operator=( const AMateria& other)
{
	std::cout << "(AMateria) Copy assignment operator called\n";
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

//destructor
AMateria::~AMateria()
{
	std::cout << "(AMateria) Destructor called\n";	
} 

//Returns the materia type
std::string const & AMateria::getType() const
{
	return type;
}

