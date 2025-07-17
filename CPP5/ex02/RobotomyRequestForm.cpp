

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

/*
Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized successfully 50% of the time. 
Otherwise, it informs that the robotomy failed.
*/

// -------------- Constructors --------------

//default
RobotomyRequestForm::RobotomyRequestForm(std::string const target):
AForm("RRF", 72, 45), _target(target)
{
	std::cout << "(RRF) Default constructor\n";
}

//copy construct
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
AForm(other.getName(), other.getGradeSign(), other.getGradeExec())
{
	std::cout << "(RRF) Copy constructor\n";
}

//copy assignment
RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm& other)
{
	std::cout << "(RRF) Copy assignment operator\n";
	if (this != &other)
	{
		_target = other.getTarget();
		// if (other.getSignedStatus()) //TODO how to assign signed status??? it is private in AForm
		// 	this->AForm::_signed = true;
	}
	return (*this);
}

//destructor //virtual so it checks itself for correct type
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "(RRF) Destructor\n";
}

// -------------- Member fts --------------

void	RobotomyRequestForm::action() const
{
	//Makes some drilling noises, then informs that <target> has been robotomized successfully 50% of the time. 
//Otherwise, it informs that the robotomy failed.
	std::cout << "..DRILLING NOISE...\n";

	bool yes = true;
	//TODO random 50% chance:

	if (yes)
		std::cout << _target << " successfully robotomized!\n";
	else	
		std::cout << "Robotomy of " << _target << "FAILED!\n";

}


const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}