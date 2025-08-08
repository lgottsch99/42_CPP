
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string	const 	_name;
		bool				_signed;
		int const			_gradeSign;
		int const			_gradeExec;

	public:
		Form(std::string const name, int const GradeSign, int const GradeExec);//default
		Form(const Form& other); //copy construct
		Form &operator=( const Form& other); //copy assignment
		~Form(); //destructor

		const std::string&	getName() const;
		const bool&			getSignedStatus() const;
		const int&			getGradeSign() const;
		const int&			getGradeExec() const;

		bool				beSigned(const Bureaucrat& bob);

		class GradeTooHighException : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};

		class GradeTooLowException : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};

};

/*
overload the insertion («) operator to print all the form’s information.
*/
std::ostream& operator<<(std::ostream& ostream, const Form& obj);


#endif