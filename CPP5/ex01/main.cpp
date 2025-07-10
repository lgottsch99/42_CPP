
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat a("a", 100);
	Form b("AGG", 120, 120);
	std::cout << a << "\n";
	std::cout << b << "\n";

	//try to sign forms
	a.signForm(b);
	std::cout << "\n\n";

	Bureaucrat c("c", 100);
	Form d("GDPR", 20, 20);
	std::cout << c << "\n";
	std::cout << d << "\n";
	c.signForm(d);
	std::cout << "\n\n";

	Bureaucrat e("e", 100);
	Form f("ABCD", 100, 100);
	std::cout << e << "\n";
	std::cout << f << "\n";
	e.signForm(f);
	std::cout << "\n\n";

	//form grade out of bounds
	//in case exception COULD be thrown-> always need to catch! otherwise std::terminate()
	try
	{
		Form z("lol", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what();
	}

	try
	{
		Form y("lolol", 190, 190);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what();
	}

	try
	{
		Form x("lololol", -5, 234);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what();
	}

	std::cout << "\n\n";
	return 0;
}