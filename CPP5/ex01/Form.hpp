
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

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

		struct GradeTooHighException;
		struct GradeTooLowException;

		const std::string&	getName() const;
		const bool&			getSignedStatus() const;
		const int&			getGradeSign() const;
		const int&			getGradeExec() const;

		bool				beSigned(int& bureauGrade);

};

/*
overload the insertion («) operator to print all the form’s information.
*/
std::ostream& operator<<(std::ostream& ostream, const Form& obj);


#endif