
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: virtual public Animal
{
	public:
		Dog(void);//default
		Dog(const Dog& other); //copy construct
		Dog &operator=( const Dog& other); //copy assignment
		~Dog(); //destructor

		void	makeSound(void) const;

};

#endif