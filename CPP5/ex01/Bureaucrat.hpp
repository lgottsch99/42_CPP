

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include "Form.hpp"

class Form; //declare here so compiler knows what to expect

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade; //1 highest, 150 lowest

	public:
		Bureaucrat(std::string const name, int const grade);//default
		Bureaucrat(const Bureaucrat& other); //copy construct
		Bureaucrat &operator=( const Bureaucrat& other); //copy assignment
		~Bureaucrat(); //destructor

		const std::string&	getName() const;
		const int&			getGrade() const;		
		void			incrementGrade();
		void			decrementGrade();

		void			signForm(Form& form);

		struct GradeTooHighException;
		struct GradeTooLowException;

};

/*
insertion («) operator to print output in the following format (without the angle brackets):
<name>, bureaucrat grade <grade>.
*/
std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& obj);

#endif