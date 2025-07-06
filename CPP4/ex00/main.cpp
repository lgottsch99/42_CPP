

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>


// https://www.w3schools.com/cpp/cpp_virtual_functions.asp

int main(void)
{
	//animal constructors------------------------
	Animal Bert;
	Animal Rosi = Bert;
	Animal Pete;

	Pete = Bert;

	Pete.makeSound();
	std::cout << "TYPE: " << Pete.getType() << "\n\n";

	//dog constructors------------------------
	Dog Sock;
	Dog Hat = Sock;
	Dog Scarf;

	Scarf = Sock;
	Sock.makeSound();
	std::cout << "TYPE: " << Sock.getType() << "\n\n";

	//Cat constructors------------------------
	Cat red;
	Cat blue = red;
	Cat green;

	green = red;

	red.makeSound();
	std::cout << "TYPE: " << red.getType() << "\n\n";

	//WrongAnimal constructors------------------------
	WrongAnimal one;
	WrongAnimal two = one;
	WrongAnimal three;

	three = one;

	one.makeSound();
	std::cout << "TYPE: " << one.getType() << "\n\n";

	//WrongCat constructors------------------------
	WrongCat a;
	WrongCat b = a;
	WrongCat c;

	c = a;

	a.makeSound(); //a is type wrongcat, no polymorphism here
	std::cout << "TYPE: " << a.getType() << "\n\n";

	//subject main: ------------------------------
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl; 
	std::cout << i->getType() << " " << std::endl; 
	i->makeSound(); //will output the cat sound! 
	j->makeSound();
    meta->makeSound();

	delete meta;
	delete j;
	delete i;

	//Wrong types ------------------------------

	const WrongAnimal* beta = new WrongAnimal(); 
	const WrongAnimal* h = new WrongCat();

	std::cout << h->getType() << " " << std::endl; 
	h->makeSound(); //will output wrong animal sound, not cat ->OK
    beta->makeSound();

	delete beta;
	delete h;

	//same with correct types -------------------------------
	const Animal* teta = new Animal(); 
	const Animal* u = new Cat();

	std::cout << u->getType() << " " << std::endl; 
	u->makeSound(); //will output correct animal sound, cat ->OK
    teta->makeSound();

	delete teta;
	delete u;

	return 0;
}