

#include "Dog.hpp"
#include <iostream>

//Con- /Destructors -------------------------
//default
Dog::Dog(void): 
A_Animal()
{
	std::cout << "(Dog) Default (void) constructor called\n";
	type = "Dog";
	brain = new Brain;
}

//copy construct
Dog::Dog(const Dog& other):
A_Animal()
{
	std::cout << "(Dog) Copy constructor called\n";
	type = other.type;
	brain = new Brain(*other.brain);
}

//copy assignment
Dog &Dog::operator=(const Dog& other)
{
	std::cout << "(Dog) Copy assignment operator called\n";
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
Dog::~Dog()
{
	delete brain;
	std::cout << "(Dog) Destructor called\n";
}

void	Dog::makeSound(void) const
{
	std::cout << "~ (Dog) woof! ~\n";
}

void	Dog::set_idea(int index, std::string idea)
{
	brain->set_idea(index, idea);
}

void	Dog::print_idea(int index)
{
	brain->print_idea(index);
}