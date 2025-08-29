
#include <string>
#include <iostream>
#include "whatever.hpp"

int main( void ) 
{
	//trying int
	int a = 2;
	int b = 3;
	
	std::cout << "a is: " << a << "\n";
	std::cout << "b is: " << b << "\n";
	
	std::cout << "swapping..\n";
	::swap( a, b );

	std::cout << "a is: " << a << "\n";
	std::cout << "b is: " << b << "\n";
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	//trying string
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c is: " << c << "\n";
	std::cout << "d is: " << d << "\n";

	std::cout << "swapping..\n";
	::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


	//trying float
	float e = 42.42;
	float f = 24.24;
	std::cout << "e is: " << e << "\n";
	std::cout << "f is: " << f << "\n";

	std::cout << "swapping..\n";
	::swap(e, f);

	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;


	return 0; 
}