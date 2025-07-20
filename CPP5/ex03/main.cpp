
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>




int main(void)
{
	Bureaucrat Boss("Boss", 1);

	Intern  someRandomIntern;
	AForm*   rrf;
	AForm*   scf;
	AForm*   ppf;
	
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "Mouse");	
	ppf = someRandomIntern.makeForm("presidential pardon", "you");	

	Boss.signForm(*rrf);
	Boss.signForm(*scf);
	//Boss.executeForm(*scf);

	//checking exception of intern (form does not exist)
	AForm *fake = NULL;
	fake = someRandomIntern.makeForm("trolol", "lol");

	delete rrf;
	delete scf;
	delete ppf;
	return 0;
}

