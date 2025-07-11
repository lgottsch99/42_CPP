
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	const 	_name;
		bool				_signed;
		int const			_gradeSign;
		int const			_gradeExec;


	public:
		AForm(std::string const name, int const GradeSign, int const GradeExec);//default
		AForm(const AForm& other); //copy construct
		AForm &operator=( const AForm& other); //copy assignment
		virtual ~AForm(); //destructor //virtual so it checks itself for correct type

		struct GradeTooHighException;
		struct GradeTooLowException;
		struct FormNotSignedExecption;

		const std::string&	getName() const;
		const bool&			getSignedStatus() const;
		const int&			getGradeSign() const;
		const int&			getGradeExec() const;

		bool				beSigned(int& bureauGrade);
		bool				execute(Bureaucrat const & executor) const;
		virtual void		action() const = 0; //making class abstract

};


/*
overload the insertion («) operator to print all the form’s information.
*/
std::ostream& operator<<(std::ostream& ostream, const AForm& obj);


#endif