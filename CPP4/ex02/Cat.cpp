
#include "Cat.hpp"
#include <iostream>

//Con- /Destructors -------------------------
//default
Cat::Cat(void): 
A_Animal()
{
	std::cout << "(Cat) Default (void) constructor called\n";
	type = "Cat";
	brain = new Brain;
}

//copy construct
Cat::Cat(const Cat& other):
A_Animal()
{
	std::cout << "(Cat) Copy constructor called\n";
	type = other.type;
	brain = new Brain(*other.brain);
}

//copy assignment
Cat &Cat::operator=(const Cat& other)
{
	std::cout << "(Cat) Copy assignment operator called\n";
	if (this != &other)
	{
		type = other.type;
		//delete old brain first
		delete brain;
		//then create new
		brain = new Brain(*other.brain);
	}
	return (*this);
}

//destructor
Cat::~Cat()
{
	delete brain;
	std::cout << "(Cat) Destructor called\n";	
}


void	Cat::makeSound(void) const
{
	std::cout << "~ (Cat) miau! ~\n";
}

void	Cat::set_idea(int index, std::string idea)
{
	brain->set_idea(index, idea);
}

void	Cat::print_idea(int index)
{
	brain->print_idea(index);
}