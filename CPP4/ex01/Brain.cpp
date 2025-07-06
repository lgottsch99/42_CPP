#include "Brain.hpp"
#include <iostream>

//Con- /Destructors -------------------------
//default
Brain::Brain(void)
{
	std::cout << "(Brain) Default (void) constructor called\n";
}

//copy construct
Brain::Brain(const Brain& other)
{
	std::cout << "(Brain) Copy constructor called\n";
	for (int i = 0; i < 100; i++)//loop over array and copy each idea
	{
		this->ideas[i] = other.ideas[i];
	}
}

//copy assignment
Brain &Brain::operator=(const Brain& other)
{
	std::cout << "(Brain) Copy assignment operator called\n";
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)//loop over array and copy each idea
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

//destructor
Brain::~Brain()
{
	std::cout << "(Brain) Destructor called\n";
}

void Brain::set_idea(int index, std::string idea)
{
	if (index >= 0 &&index < 100)
	{
		if (idea.length() <= 100)
			this->ideas[index] = idea;
		else
			std::cout << "idea too long!\n";
	}
	else
		std::cout << "idea index out of range!\n";
}

void	Brain::print_idea(int index)
{
	if (index >= 0 &&index < 100)
	{
		std::cout << this->ideas[index];
	}
	else
		std::cout << "idea index out of range!\n";

}