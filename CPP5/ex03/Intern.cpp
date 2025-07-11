
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>
#include <exception>

//----------- Constructors ------------
//default
Intern::Intern(void)
{
	std::cout << "(Intern) Default constructor\n";
}

//copy construct
Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "(Intern) Copy constructor\n";
}

//copy assignment
Intern &Intern::operator=( const Intern& other)
{
	(void)other;
	std::cout << "(Intern) Copy assignment\n";
	if (this != &other)
	{
	}
	return (*this);
}

//destructor
Intern::~Intern()
{
	std::cout << "(Intern) Destructor\n";
}

//----------- Exceptions ------------
struct Intern::FormDoesNotExistException : public std::exception {
	const char * what () const throw () {
	   return "Requested form does not exist!\n";
	}
};

//----------- Member fts ------------
int	Intern::checkFormExists(std::string formName)
{
	std::string existing[6] = {"shrubbery creation", "scf", "robotomy request", "rrf", "presidential pardon", "ppf"};
	
	int i = 0;
	while (existing[i] != formName)
		i++;

	if (i >= 6)
	{
		throw FormDoesNotExistException();
		return (-1);
	}
	return (i);
}
	

AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	AForm*	newForm = NULL;
	int 	formType = -1;

	try
	{
		formType = checkFormExists(formName);
		//make form
		switch(formType)
		{
			case 0:
			case 1:
				newForm = new ShrubberyCreationForm(formTarget);
				std::cout << "Intern creates ShrubberyCreationForm.\n";
				break;
			case 2:
			case 3:
				newForm = new RobotomyRequestForm(formTarget);
				std::cout << "Intern creates RobotomyRequestForm.\n";
				break;
			case 4:
			case 5:
				newForm = new PresidentialPardonForm(formTarget);
				std::cout << "Intern creates PresidentialPardonForm.\n";
				break;
		}
	
		return (newForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
		return (NULL);
	}
}

