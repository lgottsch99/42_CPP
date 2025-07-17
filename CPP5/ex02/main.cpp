
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

/*
TODO

actions of forms: ascii tree in scf, random in rrf

*/


int main(void)
{
	//AForm lol; //abstract

	// normal init and print stats _________________________
	Bureaucrat alf("alf", 1);
	std::cout << alf << "\n";

	ShrubberyCreationForm SCF("wolke7");
	std::cout << SCF << "\n";

	RobotomyRequestForm RRF("trashbin");
	std::cout << RRF << "\n";

	PresidentialPardonForm PPF("ralf");
	std::cout << PPF << "\n";
	
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

	// exceptions _________________________
	std::cout << "\n";

	Bureaucrat Roland("Roland", 150);
	ShrubberyCreationForm NEW_SCF("new_wolke7");

	//Roland.signForm(NEW_SCF);
	//Roland.executeForm(NEW_SCF);

	Bureaucrat Rosi("Rosi", 140);
	
	Rosi.signForm(NEW_SCF);
	Rosi.executeForm(NEW_SCF);


	return 0;
}