
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

/*
TODO

change execute function in Aform and all others:
	auslagern: gradechecks (inherit)
	-> action = execute, overwrite in inherited

*/


int main(void)
{
	//AForm lol; //abstract

	std::cout << "Normal init & print stats --------------\n";

	// normal init and print stats _________________________
	Bureaucrat alf("ralf", 1);
	std::cout << alf << "\n";

	ShrubberyCreationForm SCF("wolke7");
	std::cout << SCF << "\n";

	RobotomyRequestForm RRF("trashbin");
	std::cout << RRF << "\n";

	PresidentialPardonForm PPF("ralf");
	std::cout << PPF << "\n";
	

	std::cout << "\n\nsigning + exec check  --------------\n";
	// signing + exec check _________________________
	std::cout << "\n";

	alf.signForm(SCF);
	std::cout << SCF << "\n";
	alf.executeForm(SCF);

	alf.signForm(RRF);
	std::cout << RRF << "\n";
	alf.executeForm(RRF);

	alf.signForm(PPF);
	std::cout << PPF << "\n";
	alf.executeForm(PPF);


	std::cout << "\n\nexceptions  --------------\n";
	// exceptions _________________________
	std::cout << "\n";

	Bureaucrat Roland("Roland", 150);
	ShrubberyCreationForm NEW_SCF("new_wolke7");

	Roland.signForm(NEW_SCF);
	Roland.executeForm(NEW_SCF);

	Bureaucrat Rosi("Rosi", 140);
	
	Rosi.signForm(NEW_SCF);
	std::cout << "\n";
	Rosi.executeForm(NEW_SCF);
	std::cout << "\n";
	return 0;
}