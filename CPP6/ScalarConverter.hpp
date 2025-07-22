
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <exception>
/*
As this class doesn’t need to store anything at all, it must not be instantiable by users.
Except for char parameters, only the decimal notation will be used.
*/

class ScalarConverter
{	
	private:
		static void	check_print(std::string &str);

		ScalarConverter(void);//default
		ScalarConverter(const ScalarConverter& other); //copy construct
		ScalarConverter &operator=( const ScalarConverter& other); //copy assignment
		~ScalarConverter(); //destructor

	public:
		// ScalarConverter(void);//default
		// ScalarConverter(const ScalarConverter& other); //copy construct
		// ScalarConverter &operator=( const ScalarConverter& other); //copy assignment
		// ~ScalarConverter(); //destructor

		class CharNotDisplayable : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};

		static void convert(std::string str);
};

#endif