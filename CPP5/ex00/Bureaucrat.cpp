
#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>


// -------------- Exceptions --------------

char const *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	   return ("Grade too high! (less than 1)\n");
};

char const *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	   return ("Grade too low! (more than 150)\n");
};

// -------------- Constructors --------------


//default
Bureaucrat::Bureaucrat(std::string const name, int const grade):
_name(name), _grade(grade)
{
	std::cout << "(Bureaucrat) Default constructor\n";
	if (_grade < 1)
		throw GradeTooHighException();
	else if(_grade > 150)
		throw GradeTooLowException();
}

//copy construct
Bureaucrat::Bureaucrat(const Bureaucrat& other):
_name(other.getName()), _grade(other.getGrade())
{
	std::cout << "(Bureaucrat) Copy constructor\n";
}

//copy assignment
Bureaucrat &Bureaucrat::operator=( const Bureaucrat& other)
{
	std::cout << "(Bureaucrat) Copy assignment operator\n";
	if (this != &other)
	{
		_grade = other.getGrade();
	}
	return (*this);
}

//destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "(Bureaucrat) Destructor\n";
}

// -------------- Member Fts --------------

const std::string&	Bureaucrat::getName() const 
{
	return (_name);
}

const int&			Bureaucrat::getGrade() const
{
	return (_grade);
}

void			Bureaucrat::incrementGrade() //TODO exceptions
{
	if (_grade >= 2)
		_grade--;
	else //throw exception too big?
		throw GradeTooHighException();

}

void			Bureaucrat::decrementGrade() //TODO exceptions
{
	if (_grade <= 149)
		_grade++;
	else //throw exception too small?
		throw GradeTooLowException();

}

// -------------- Operators --------------
/*
insertion («) operator to print output in the following format (without the angle brackets):
<name>, bureaucrat grade <grade>.
*/
std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& obj)
{
	ostream << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n";
	return (ostream);
}