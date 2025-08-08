
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	std::cout << "Basic init ----------------\n\n";

	Bureaucrat a("pete", 1);

	//Basic Tests

	// << operator 
	std::cout << a;

	Bureaucrat b("rita", 3);
	std::cout << b;
	b = a;
	std::cout << b;


	std::cout << "\nInit out of range exception ----------------\n\n";

	try
	{
		std::cout << "Bureaucrat d(Ralf, 156);\n";
		Bureaucrat d("Ralf", 156);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what();
	}

	try
	{
		std::cout << "Bureaucrat d(Ulf, 0);\n";
		Bureaucrat d("Ulf", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what();
	}

	std::cout << "\nINcrement out of range exception ----------------\n\n";

	
	//Exceptions
	try
	{
		std::cout << "trying to increment " << a << "\n";
		a.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what();
	}
	
	std::cout << "DEcrement out of range exception ----------------\n\n";

	Bureaucrat c("lola", 120);

	try
	{
		while (1)
		{
			c.decrementGrade();
			std::cout << "decremented grade of " << c;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what();
	}

}