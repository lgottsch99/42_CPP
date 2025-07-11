
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

/*
TODO

*/


int main(void)
{
	Bureaucrat Boss("Boss", 1);

	Intern  someRandomIntern;
	AForm*   rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");	

	Boss.signForm(*rrf);

	delete rrf;
	return 0;
}

