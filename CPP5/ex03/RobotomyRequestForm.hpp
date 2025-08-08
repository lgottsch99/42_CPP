
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

/*
Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized successfully 50% of the time. 
Otherwise, it informs that the robotomy failed.
*/

#include "AForm.hpp"

class RobotomyRequestForm: virtual public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm(std::string const target);//default
		RobotomyRequestForm(const RobotomyRequestForm& other); //copy construct
		RobotomyRequestForm &operator=( const RobotomyRequestForm& other); //copy assignment
		virtual ~RobotomyRequestForm(); //destructor //virtual so it checks itself for correct type

		// void	action() const;
		virtual bool		execute(Bureaucrat const & executor) const;

		const std::string&	getTarget(void) const;
};

#endif