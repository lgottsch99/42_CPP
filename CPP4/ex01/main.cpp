

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

/*
Shallow Copy: Copies pointers as-is, meaning multiple objects point to the same memory. Changing one changes all.
Deep Copy: Allocates new memory and duplicates the actual contents — changes to one object don't affect the other.
*/

// https://www.w3schools.com/cpp/cpp_virtual_functions.asp

int main(void)
{
	int N = 10;
	int even = N % 2;
	if (even == 1)
	{
		std::cout << "number not even, pls define even number\n";
		return 1;
	}
	Animal *array[N];

	std::cout << "Assigning dogs and cats to array \n\n";
	int i = 0;
	while (i < N/2)
	{
		array[i] = new Dog;
		i++; 
	}
	while (i < N)
	{
		array[i] = new Cat;
		i++;
	}
	i = 0;
	while (i < N)
	{
		array[i]->makeSound();
		i++;
	}

	//checking if deep copy(aka all pointers etc are duplicated NOT SHARED)
	std::cout << "\n\nProving deep copies: \n\n";

	std::cout << "Init 2 og objects: \n";

	Cat *a = new Cat;
	Dog *z = new Dog;
	a->set_idea(0, "eat fish\n");
	z->set_idea(0, "chase cat\n");

	std::cout << "\nCat a idea: ";
	a->print_idea(0);
	std::cout << "\nDog z idea: ";
	z->print_idea(0);

	std::cout << "\nCOPY CONSTRUCT 2 more objects, based on ogs:\n\n";
	Cat *b = new Cat(*a);
	Dog *y = new Dog(*z);
	std::cout << "\nCat b idea: ";
	b->print_idea(0);
	std::cout << "\nDog y idea: ";
	y->print_idea(0);

	std::cout << "\n...Now changing ideas of new obj!\n";


	b->set_idea(0, "eat pizza\n");
	y->set_idea(0, "watch tv\n");
	std::cout << "\nafter changing b's idea, all IDEAS should be DIFFERENT:\n\n";
	std::cout << "Cat a idea: ";
	a->print_idea(0);
	std::cout << "Cat b idea: ";
	b->print_idea(0);
	std::cout << "Dog z idea: ";
	z->print_idea(0);
	std::cout << "Dog y idea: ";
	y->print_idea(0);

	delete a;
	delete b;
	delete z;
	delete y;

	std::cout << "\ndeleting array...\n";
	//deleting array
	i = 0;
	while (i < N)
	{
		delete array[i]; //for this to work, destructor needs to be virtual! only then choosing correct type
		i++;
	}
	return 0;
}