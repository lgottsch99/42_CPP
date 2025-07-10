
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat a("pete", 1);

	//Basic Tests

	// << operator 
	std::cout << a;

	Bureaucrat b("rita", 3);
	std::cout << b;
	b = a;
	std::cout << b;

	try
	{
		Bureaucrat d("Ralf", 156);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what();
	}

	try
	{
		Bureaucrat d("Ulf", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what();
	}



	//Exceptions
	try
	{
		a.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what();
	}
	

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

	try
	{
		while (1)
		{
			c.incrementGrade();
			std::cout << "incremented grade of " << c;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what();
	}

	
}