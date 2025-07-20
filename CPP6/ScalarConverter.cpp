

#include "ScalarConverter.hpp"
#include <iostream>


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

//----------- Methods ------------
 
void	ScalarConverter::check_print(std::string &str)
{
	//loop thru str
	for (unsigned long i = 0; i < str.length(); i++)
	{
		int c = static_cast<int>(str[i]);
		if (c < 32 || c > 255)
			throw CharNotDisplayable();
	}
	return;
}

/*
what type of input can i expect?? 

1234 34567?
hellow orld?

what if one doesnt work, all others error too?

--->see 2nd part testing program!

Literal Type	Literal in Code	String Representation Passed to convert()
char	'a'		"a" or 'a' → "a"
int		42		"42"
float	4.2f	"4.2f"
double	4.2		"4.2"
special literals	nan, +inf	"nan", "+inf", "-inf"

*/
void ScalarConverter::convert(std::string &str)
{
	//string like "hello"  -> invalid input?
	//string like "4.9f" -> char output = "4.9f"(string), all others just numbers 
	std::string c;
	// int i;
	// float f;
	// double d;
	//output its value in the following series of scalar types: char, int, float, double

	try
	{
		//check printability
		check_print(str);
		c = str;

		//check for "-inff, +inff, and nanf" | "-inf, +inf, and nan."
		// i = convert_int(str);
		// f = convert_float(str);
		// d = convert_double(str);
		
		// //else: check for last char f AND all others digit or .-

		// print_conv(c, i, f, d);

	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}

}
