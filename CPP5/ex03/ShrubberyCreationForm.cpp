

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

/*
ShrubberyCreationForm: Required grades: sign 145, exec 137
Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
*/

// -------------- Constructors --------------

//default
ShrubberyCreationForm::ShrubberyCreationForm(std::string const target):
AForm("SCF", 145, 137), _target(target)
{
	std::cout << "(SCF) Default constructor\n";
}

//copy construct
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
AForm(other.getName(), other.getGradeSign(), other.getGradeExec())
{
	std::cout << "(SCF) Copy constructor\n";
}

//copy assignment
ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other)
{
	std::cout << "(SCF) Copy assignment operator\n";
	if (this != &other)
	{
		// if (other.getSignedStatus()) //TODO how to assign signed status??? it is private in AForm
		// 	this->AForm::_signed = true;
	}
	return (*this);
}

//destructor //virtual so it checks itself for correct type
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "(SCF) Destructor\n";
}

// -------------- Member fts --------------

void	ShrubberyCreationForm::action() const
{
	//Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
	//checks are done in AForm::execute
	std::ofstream	outfile;
	std::string		filename = "_shrubbery";

	filename = _target + filename;

	//TODO write ascii trees in it
	outfile.open (filename);
	outfile << "ASCII TREES\n";
	outfile.close();

}


