
#include "Iter.hpp"
#include <string>

int main (void)
{
	std::cout << "\n----- Int array: \n\n";
	int 				int_array[] = {4, 3, 2, 1};
	::iter(int_array, 4, print_array<int>); //need to explicity instantiate print_array bc it is a template: "print_array<int>" lets compiler create the int version of ft

	std::cout << "\n----- Const int array: \n\n";
	const int			const_int_array [] = {1, 2, 3, 4};
	::iter(const_int_array, 4, print_array<const int>);

	std::cout << "\n----- String array: \n\n";
	std::string			str_array[] = {"hello", "hi", "hey", "ciao"};
	::iter(str_array, 4, print_array<std::string>);

	std::cout << "\n----- Const String array: \n\n";
	const std::string	const_str_array[] = {"hello", "hi", "hey", "ciao"};
	::iter(const_str_array, 4, print_array<const std::string>);

}