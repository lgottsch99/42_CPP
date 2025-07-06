
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: virtual public Animal
{
	private: 
		Brain *brain;

	public:
		Dog(void);//default
		Dog(const Dog& other); //copy construct
		Dog &operator=( const Dog& other); //copy assignment
		~Dog(); //destructor

		void	makeSound(void) const;
		void	set_idea(int index, std::string idea);
		void	print_idea(int index);


};

#endif