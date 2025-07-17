
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

/*
Required grades: sign 25, exec 5 Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/

#include "AForm.hpp"

class PresidentialPardonForm: virtual public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(std::string const target);//default
		PresidentialPardonForm(const PresidentialPardonForm& other); //copy construct
		PresidentialPardonForm &operator=( const PresidentialPardonForm& other); //copy assignment
		virtual ~PresidentialPardonForm(); //destructor //virtual so it checks itself for correct type

		void				action() const;

		const std::string&	getTarget(void) const;
};

#endif