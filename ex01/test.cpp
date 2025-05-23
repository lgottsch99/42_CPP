
#include <iostream>
#include <string>


int main(void)
{
	std::string test;

	std::cout << "Enter sth: ";
	getline(std::cin, test);

	std::cout.setf(std::ios::right);
	std::cout.width(10);

	std::cout << test << "\n";


}