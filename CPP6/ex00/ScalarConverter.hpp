
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <exception>
#include <iostream>
#include <limits>

/*
As this class doesn’t need to store anything at all, it must not be instantiable by users.
Except for char parameters, only the decimal notation will be used.
*/

class ScalarConverter
{	
	private:
		static void	convert_from_char(char& c);
		static bool	is_int(std::string str);
		static void	convert_from_int(std::string str);
		static bool	is_float(std::string str);
		static void	convert_from_float(std::string str);
		static bool	is_double(std::string str);
		static void	convert_from_double(std::string str);

		ScalarConverter(void);//default
		ScalarConverter(const ScalarConverter& other); //copy construct
		ScalarConverter &operator=( const ScalarConverter& other); //copy assignment
		~ScalarConverter(); //destructor

		class CharNotDisplayable : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};
		class InvalidInput : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};

	public:
		static void convert(std::string str);
};

#endif