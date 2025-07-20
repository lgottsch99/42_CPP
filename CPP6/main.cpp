
#include "ScalarConverter.hpp"
#include <iostream>

int main (void)
{
	ScalarConverter a;

	std::cout << "Basic func ----------------\n\n";

	std::string c = "a";
	std::string i = "2";
	std::string f = "1.4f";
	std::string d = "4.2";



	std::cout << "Exceptions ----------------\n\n";
	std::string wrong1 = "hello";
	std::string wrong2 = "\t\v";

	a.convert(wrong2);


	return 0;
}