

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>


// -------------- Exceptions --------------

char const *Form::GradeTooHighException::what(void) const throw()
{
	   return ("Form: Grade too high!\n");
};

char const *Form::GradeTooLowException::what(void) const throw()
{
	   return ("Form: Grade too low!\n");
};


// -------------- Constructors --------------
//default
Form::Form(std::string const name, int const GradeSign, int const GradeExec):
_name(name), _signed(false), _gradeSign(GradeSign), _gradeExec(GradeExec)
{
	std::cout << "(Form) Default constructor\n";
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
}

//copy construct
Form::Form(const Form& other):
_name(other.getName()), _signed(other.getSignedStatus()), _gradeSign(other.getGradeSign()), _gradeExec(other.getGradeExec())
{
	std::cout << "(Form) Copy constructor\n";
}

//copy assignment
Form& Form::operator=( const Form& other)
{
	std::cout << "(Form) Copy assignment operator\n";
	if (this != &other)
	{
		// _name = other.getName(); //const data cannot be reassigned!
		_signed = other.getSignedStatus();
		// _gradeSign = other.getGradeSign();//const data cannot be reassigned!
		// _gradeExec = other.getGradeExec();//const data cannot be reassigned!
	}
	return (*this);
}

//destructor
Form::~Form()
{
	std::cout << "(Form) Destructor\n";
}


// -------------- Getters & Functions --------------

const std::string&	Form::getName() const
{
	return (_name);
}

const bool&			Form::getSignedStatus() const
{
	return (_signed);
}

const int&			Form::getGradeSign() const
{
	return (_gradeSign);
}

const int&			Form::getGradeExec() const
{
	return (_gradeExec);
}

//add a beSigned() member function to the Form that takes a Bureaucrat as a
//parameter
bool				Form::beSigned(const Bureaucrat& bob)
{
	if (bob.getGrade() > _gradeSign) //eg bureau grade: 123; form gradeSIgn: 100
	{
		throw GradeTooLowException();
		return false;
	}
	else
	{
		_signed = true;
		return true;
	}		
}


// -------------- Other --------------

/*
overload the insertion («) operator to print all the form’s information.
*/
std::ostream& operator<<(std::ostream& ostream, const Form& obj)
{
	std::string	status;

	if (obj.getSignedStatus() == true)
		status = "true";
	else
		status = "false";
	
	ostream << "Form name:     " << obj.getName() << "\n"
			<< "Signed Status: " << status << "\n"
			<< "Grade to sign: " << obj.getGradeSign() << "\n"
			<< "Grade to exec: " << obj.getGradeExec() << "\n";
	return (ostream);
}
