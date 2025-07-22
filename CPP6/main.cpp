
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong input. Usage: ./convert literal\n";
		return 0;
	}
	std::cout << "Correct input, converting...\n";
	
	ScalarConverter::convert(std::string(argv[1]));


	return 0;
}