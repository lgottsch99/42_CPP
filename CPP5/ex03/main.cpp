
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

/*
TODO

test, segfault etc

*/


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
	Boss.executeForm(*scf);
	Boss.executeForm(*rrf);

	//checking exception of intern (form does not exist)
	AForm *fake = NULL;
	try
	{
		fake = someRandomIntern.makeForm("lol", "lol"); //problem before: catching exception inside makeform -> exception doesnt reach this try catch block ->deref null ptr/ crash
		Boss.signForm(*fake);
		if (fake)
			delete fake;

	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	delete rrf;
	delete scf;
	delete ppf;
	return 0;
}

