

#include "ScalarConverter.hpp"
#include <iostream>

#include <cctype>
#include <climits>
#include <iostream>
#include <ctype.h>
#include <iomanip>      // std::setprecision
#include <stdlib.h>     /* strtod */

//----------- Constructors ------------
//default
ScalarConverter::ScalarConverter(void)
{
	std::cout << "(ScalarConverter) Default constructor\n";
}

//copy construct
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
	std::cout << "(ScalarConverter) Copy constructor\n";
}

//copy assignment
ScalarConverter &ScalarConverter::operator=( const ScalarConverter& other)
{
	(void)other;
	std::cout << "(ScalarConverter) Copy assignment\n";
	if (this != &other)
	{
	}
	return (*this);
}

//destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "(ScalarConverter) Destructor\n";
}

//----------- Exceptions ------------

char const *ScalarConverter::CharNotDisplayable::what(void) const throw()
{
	return("(ScalarConverter) EXCEPTION: Input Char not displayable!\n");
}

char const *ScalarConverter::InvalidInput::what(void) const throw()
{
	return("(ScalarConverter) EXCEPTION: Invalid Input!\n");
}

//----------- Methods ------------
 
// void	ScalarConverter::check_print(std::string &str)
// {
// 	//loop thru str
// 	for (unsigned long i = 0; i < str.length(); i++)
// 	{
// 		int c = static_cast<int>(str[i]);
// 		if (c < 32 || c > 255)
// 			throw CharNotDisplayable();
// 	}
// 	return;
// }

void	ScalarConverter::convert_from_char(char& c)
{
	std::cout << "OG TYPE: char\n";
	// std::cout << "c to convert: " << c << "\n";
	std::cout << "char: ";
	//check if printable
	if (isprint(c) == 0)
		std::cout << "not displayable!\n";
	else
		std::cout << "\'" << c << "\'\n";
	
	//convert	
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f\n";
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(c) << "\n";
	
}

bool	ScalarConverter::is_int(std::string str)
{ //return if str is valid int
	//INT_MIN = -2147483648 
	//INT_MAX = 2147483647

	long number; //!overflow

	if (str.length() <= 11)
	{
		if (str[0] == '-' || isdigit(str[0]))
		{
			// std::cout << "first is - or digit\n";

			bool valid = true;
			for (size_t i = 1; i < str.length(); i++) //check only correct digits
			{
				if (!isdigit(str[i]))
					valid = false;
			}
			if (valid) //check if within INT range
			{
				number = atol(str.c_str());
				// std::cout << "number is: " << number << "\n\n";

				if (number >= INT32_MIN && number <= INT32_MAX)
					return true;
			}
		}
	}
	return false;
}

void	ScalarConverter::convert_from_int(std::string str)
{
	std::cout << "OG TYPE: int\n";
	int number = static_cast<int>(atoi(str.c_str()));
	// std::cout << "in convert from INT\n";

	//char 
	std::cout << "char: ";
	//check if printable
	if (number >= 0 && number <= 255 && isprint(number))
		std::cout << "\'" << static_cast<char>(number) << "\'" <<"\n";
	else if (number >= 0 && number < 256 && isprint(number) == 0)
		std::cout << "not displayable!\n";
	else 
		std::cout << "impossible!\n";
	
	//int
	std::cout << "Int: " << number << "\n";

	//float
	std::cout << std::fixed << std::setprecision(1) << "Float: " << static_cast<float>(number) << "f\n";
	//double
	std::cout << std::fixed << std::setprecision(1) << "Double: " << static_cast<double>(number) << "\n";

}

bool	ScalarConverter::is_float(std::string str)
{
	// std::cout << "\ncheck if float...\n";
	int dots = 0;
	std::string first = "0123456789+-";

	if (str.length() <= 1)
		return false;
 //check -inff, +inff, and nanf.
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;

//check only one .
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			dots++;
	} //check if last char f
	if (dots != 1 || str[str.length() - 1] != 'f')
		return false;

	//check first if +- or digit (NO DOT)
	if (first.find(str[0]) != std::string::npos)
	{
		bool valid_dot = false;
		//go thru str and check if only digits or single valid dot
		for (size_t i = 1; i < (str.length() - 1); i++)
		{
			if (!isdigit(str[i]) && str[i] != '.') // if any not digit direct return 
				return false;
			if (str[i] == '.') //before and after dot needs to be a digit!
			{
				//dot cannot be last 
				if (i == str.length() - 1)
					valid_dot = false;
				if (isdigit(str[i - 1]) && isdigit(str[i + 1]))
					valid_dot = true;
			}
		}
		if (valid_dot)
			return true;
	}
	return false;
}

void	ScalarConverter::convert_from_float(std::string str)
{
	std::cout << "OG TYPE: float\n";
	//nan -inff +inff
	if (str == "nanf" || str == "-inff" || str == "+inff")
	{
		std::cout << "char: impossible!\nint: impossible!\n";
		if (str == "nanf")
			std::cout << "float: nanf\ndouble: nan\n";
		else if (str == "-inff")
			std::cout << "float: -inff\ndouble: -inf\n";
		else if (str == "+inff")
			std::cout << "float: +inff\ndouble: +inf\n";
		return;
	}

	//normal float number
	float number = static_cast<float>(atof(str.c_str()));
	// std::cout << "test float is : " << number << "\n";

	std::cout << "char: ";
	//check if printable
	if (number >= 0 && number <= 255 && isprint(number))
		std::cout << "\'" << static_cast<char>(number) << "\'" <<"\n";
	else if (number >= 0 && number < 256 && isprint(number) == 0)
		std::cout << "not displayable!\n";
	else 
		std::cout << "impossible!\n";
	
	//int
	std::cout << "int: ";
	if (number >= INT32_MIN && number <= INT32_MAX)
		std::cout << static_cast<int>(number) << "\n";
	else
		std::cout << "impossible!\n";

	//float
	std::cout << std::fixed << std::setprecision(1) << "float: " << number << "f\n";
	//double
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(number) << "\n";
	
}

bool	ScalarConverter::is_double(std::string str)
{
	// std::cout << "\ncheck if double...\n";
	int dots = 0;
	std::string first = "0123456789+-";

	if (str.length() <= 1)
		return false;
 //check -inf, +inf, and nan
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;

//check only one .
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			dots++;
	} //check if last char f
	if (dots != 1)
		return false;

	//check first if +- or digit (NO DOT)
	if (first.find(str[0]) != std::string::npos)
	{
		bool valid_dot = false;
		//go thru str and check if only digits or single valid dot
		for (size_t i = 1; i < (str.length() - 1); i++)
		{
			if (!isdigit(str[i]) && str[i] != '.') // if any not digit direct return 
				return false;
			if (str[i] == '.') //before and after dot needs to be a digit!
			{
				//dot cannot be last 
				if (i == str.length() - 1)
					valid_dot = false;
				if (isdigit(str[i - 1]) && isdigit(str[i + 1]))
					valid_dot = true;
			}
		}
		if (valid_dot)
			return true;
	}
	return false;
}

void	ScalarConverter::convert_from_double(std::string str)
{
	std::cout << "OG TYPE: double\n";
	//nan -inf +inf
	if (str == "nan" || str == "-inf" || str == "+inf")
	{
		std::cout << "char: impossible!\nint: impossible!\n";
		if (str == "nan")
			std::cout << "float: nanf\ndouble: nan\n";
		else if (str == "-inf")
			std::cout << "float: -inff\ndouble: -inf\n";
		else if (str == "+inf")
			std::cout << "float: +inff\ndouble: +inf\n";
		return;
	}

	//normal float number
	double number = static_cast<double>(atof(str.c_str()));

	std::cout << "char: ";
	//check if printable
	if (number >= 0 && number <= 255 && isprint(number))
		std::cout << "\'" << static_cast<char>(number) << "\'" <<"\n";
	else if (number >= 0 && number < 256 && isprint(number) == 0)
		std::cout << "not displayable!\n";
	else 
		std::cout << "impossible!\n";
	
	//int
	std::cout << "int: ";
	if (number >= INT32_MIN && number <= INT32_MAX)
		std::cout << static_cast<int>(number) << "\n";
	else
		std::cout << "impossible!\n";
	//float
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(number) << "f\n";
	//double
	std::cout << std::fixed << std::setprecision(1) << "double: " << number << "\n";
	

}


void ScalarConverter::convert(std::string str)
{
	//1.detect type of literal
	//2. cast & print starting from correct type
	try
	{
		if (str.length() == 0)
			throw InvalidInput();
		
		//char
		else if (str.length() == 1 && !std::isdigit(str[0]))
			convert_from_char(str[0]);
		else if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') //pass like ./convert "'g'"
			convert_from_char(str[1]);
		//int
		else if (is_int(str))
			convert_from_int(str);
		//float
		else if (is_float(str))
		 	convert_from_float(str);
		//double
		else if (is_double(str))
		 	convert_from_double(str);
		else	
			throw InvalidInput();

	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

}
