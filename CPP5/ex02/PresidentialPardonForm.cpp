

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

/*
Required grades: sign 25, exec 5 Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/

// -------------- Constructors --------------

//default
PresidentialPardonForm::PresidentialPardonForm(std::string const target):
AForm("PPF", 25, 5), _target(target)
{
	std::cout << "(PPF) Default constructor\n";
}

//copy construct
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
AForm(other.getName(), other.getGradeSign(), other.getGradeExec())
{
	std::cout << "(PPF) Copy constructor\n";
}

//copy assignment
PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm& other)
{
	std::cout << "(PPF) Copy assignment operator\n";
	if (this != &other)
	{
		_target = other.getTarget();
		// if (other.getSignedStatus()) //TODO how to assign signed status??? it is private in AForm
		// 	this->AForm::_signed = true;
	}
	return (*this);
}

//destructor //virtual so it checks itself for correct type
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "(PPF) Destructor\n";
}

// -------------- Member fts --------------


bool	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (CheckSignGrades(executor) == true)
		{

		//Required grades: sign 25, exec 5 Informs that <target> has been pardoned by Zaphod Beeblebrox.
			std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
			return true;
		}
		return false;
	}
	catch(const std::exception& e)
	{
		std::cout << executor.getName() << " CANNOT execute " << this->getName() << " because: " << e.what() << '\n';
		return false;
	}
}


const std::string&	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

