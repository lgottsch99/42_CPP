

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>


// -------------- Exceptions --------------

struct AForm::GradeTooHighException : public std::exception {
	const char * what () const throw () {
	   return "Grade too high!\n";
	}
};

struct AForm::GradeTooLowException : public std::exception {
	const char * what () const throw () {
	   return "Grade too low!\n";
	}
};

struct AForm::FormNotSignedExecption : public std::exception {
	const char * what () const throw () {
	   return "Form not signed! Cannot be executed!\n";
	}
};

// -------------- Constructors --------------
//default 
AForm::AForm(std::string const name, int const GradeSign, int const GradeExec):
_name(name), _signed(false), _gradeSign(GradeSign), _gradeExec(GradeExec)
{
	std::cout << "(AForm) Default constructor\n";
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
}

//copy construct 
AForm::AForm(const AForm& other):
_name(other.getName()), _signed(other.getSignedStatus()), _gradeSign(other.getGradeSign()), _gradeExec(other.getGradeExec())
{
	std::cout << "(AForm) Copy constructor\n";
}

//copy assignment 
AForm& AForm::operator=( const AForm& other)
{
	std::cout << "(AForm) Copy assignment operator\n";
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
AForm::~AForm()
{
	std::cout << "(AForm) Destructor\n";
}


// -------------- Getters & Functions --------------

const std::string& AForm::getName() const
{
	return (_name);
}

const bool&		 AForm::getSignedStatus() const
{
	return (_signed);
}

const int&		 AForm::getGradeSign() const
{
	return (_gradeSign);
}

const int&		 AForm::getGradeExec() const
{
	return (_gradeExec);
}

bool			 AForm::beSigned(const Bureaucrat& bob)
{
	if (bob.getGrade() > _gradeSign) //eg bureau grade: 123; Aform gradeSIgn: 100
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


bool	AForm::execute(Bureaucrat const & executor) const
{
	try
	{
		//check if form is signed
		if (!getSignedStatus())
			throw FormNotSignedExecption();
		//check if bureau exec grade high enough
		if (executor.getGrade() > _gradeExec)
			throw GradeTooLowException();
		
		action();
		return true;
	}
	catch(const std::exception& e)
	{
		std::cout << executor.getName() << " CANNOT execute " << this->getName() << " because: " << e.what() << '\n';
		return false;
	}
}



// -------------- Other --------------

/*
overload the insertion («) operator to print all the Aform’s i Aformation.
*/
std::ostream& operator<<(std::ostream& ostream, const AForm& obj)
{
	std::string	status;

	if (obj.getSignedStatus() == true)
		status = "true";
	else
		status = "false";
	
	ostream << "AForm name:    " << obj.getName() << "\n"
			<< "Signed Status: " << status << "\n"
			<< "Grade to sign: " << obj.getGradeSign() << "\n"
			<< "Grade to exec: " << obj.getGradeExec() << "\n";
	return (ostream);
}
