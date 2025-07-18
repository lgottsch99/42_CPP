

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <stdlib.h> 

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

	srand(std::time(NULL)); //seed for rand (aka setting internal algo params for random numbers), otherwise rand always the same
	int yes = std::rand() % 2;

	if (yes == 1)
		std::cout << _target << " SUCCESSfully robotomized!\n";
	else	
		std::cout << "Robotomy of " << _target << " FAILED!\n";

}


const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}