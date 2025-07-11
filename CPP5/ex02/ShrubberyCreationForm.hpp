
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

/*
ShrubberyCreationForm: Required grades: sign 145, exec 137
Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
*/

#include "AForm.hpp"

class ShrubberyCreationForm: virtual public AForm
{
	private:
		std::string const	_target;

	public:
		ShrubberyCreationForm(std::string const target);//default
		ShrubberyCreationForm(const ShrubberyCreationForm& other); //copy construct
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm& other); //copy assignment
		virtual ~ShrubberyCreationForm(); //destructor //virtual so it checks itself for correct type

		void	action() const;

};

#endif