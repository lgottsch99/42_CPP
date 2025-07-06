
#include "Ice.hpp"
#include <iostream>
#include <string>

//default
Ice::Ice(std::string const & type):
AMateria("ice")
{
	std::cout << "(Ice) default constructor called";
}

//copy construct
Ice::Ice(const Ice& other):
AMateria("ice")
{
	std::cout << "(Ice) copy constructor called";
}

//copy assignment
Ice &Ice::operator=( const Ice& other)
{
	std::cout << "(Ice) Copy assignment operator called\n";

	if(this != &other)
	{
	}
	return (*this);
}

//destructor
Ice::~Ice()
{
	std::cout << "(Ice) Destructor called\n";	
}

//MEMBERS ------------------

//returns new cloned instance
Ice* Ice::clone(void)
{
	Ice *n;
	n = new Ice;
	return (n);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target << " *";
}
