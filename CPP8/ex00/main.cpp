
#include "easyfind.hpp"

#include <vector>
#include <string>
#include <list>

int main(void)
{
	// Initializing the vector elements
    std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(3);

	std::vector<int>::iterator it_one = easyfind<std::vector<int> >(vec, 3);
	if (it_one != vec.end())
		std::cout << "Found at index: " << std::distance(vec.begin(), it_one) << "\n";
	else
		std::cout << "Not found!\n";

	std::vector<int>::iterator it_two = easyfind<std::vector<int> >(vec, 6);
	if (it_two != vec.end())
		std::cout << "Found at index: " << std::distance(vec.begin(), it_two) << "\n";
	else
		std::cout << "Not found!\n";



	// Initializing the list elements
    std::list<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(3);

	std::list<int>::iterator it_three = easyfind<std::list<int> >(list, 3);
	if (it_three != list.end())
		std::cout << "Found at index: " << std::distance(list.begin(), it_three) << "\n";
	else
		std::cout << "Not found!\n";

	std::list<int>::iterator it_four = easyfind<std::list<int> >(list, 6);
	if (it_four != list.end())
		std::cout << "Found at index: " << std::distance(list.begin(), it_four) << "\n";
	else
		std::cout << "Not found!\n";
}