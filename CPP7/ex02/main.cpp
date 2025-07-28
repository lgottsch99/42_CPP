
#include "Array.hpp"
#include <string>

int main(void)
{
	//todo check valgrind

	std::cout << "\nstring -----------\n";
	Array<std::string> str_array_empty;
	Array<std::string> str_array(3);

	str_array[0] = "hello";
	str_array[1] = "world";
	str_array[2] = "bye!";


	std::cout << "size of str_array_empty: " << str_array_empty.size() << "\n";
	std::cout << "size of str_array: " << str_array.size() << "\n";
	try
	{
		std::cout << "\nstr_array at size + 1: " << str_array[str_array.size() + 1] << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	//copy construcr
	Array<std::string> str_array_copy(str_array);
	for (int i = 0; i < str_array_copy.size(); i++)
	{
		std::cout << str_array_copy[i] << "\n";
	}

	std::cout << "\nchanging element in copy array: \n";
	//check modification of copy
	str_array_copy[0] = "I CHANGED STH!";
	for (int i = 0; i < str_array_copy.size(); i++)
	{
		std::cout << "COPY: " << str_array_copy[i] << "\n";
		std::cout << "OG:   " << str_array[i] << "\n";
	}

	//copy assignment
	Array<std::string> equal = str_array;
	std::cout <<"\n";
	for (int i = 0; i < equal.size(); i++)
	{
		std::cout << "=: " << equal[i] << "\n";
		std::cout << "OG:   " << str_array[i] << "\n";
	}



	std::cout << "\n\nint -----------\n";
	
	int * a = new int();
	std::cout << *a << "\n";

	Array<int> int_array_empty;
	Array<int> int_array(3);

	int_array[0] = 123;
	int_array[1] = 456;
	int_array[2] = 789;

	std::cout << "size of int_array_empty: " << int_array_empty.size() << "\n";
	std::cout << "size of int_array: " << int_array.size() << "\n";
	try
	{
		std::cout << "\nint_array at size + 1: " << int_array[int_array.size() + 1] << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	//copy conintucr
	Array<int> int_array_copy(int_array);
	for (int i = 0; i < int_array_copy.size(); i++)
	{
		std::cout << int_array_copy[i] << "\n";
	}

	std::cout << "\nchanging element in copy array: \n";
	//check modification of copy
	int_array_copy[0] = 111100000;
	for (int i = 0; i < int_array_copy.size(); i++)
	{
		std::cout << "COPY: " << int_array_copy[i] << "\n";
		std::cout << "OG:   " << int_array[i] << "\n";
	}





	}