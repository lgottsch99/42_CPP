

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
/*
Destructor needs to be virtual
"virtual" will make compiler check for correct object (w/o always the base class version will be used)
*/
class Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);//default
		Animal(const Animal& other); //copy construct
		Animal &operator=( const Animal& other); //copy assignment
		virtual ~Animal(); //destructor 

		virtual void	makeSound(void) const; 

		const std::string& getType(void) const;
};

#endif