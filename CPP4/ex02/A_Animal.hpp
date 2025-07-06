

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
/*
Destructor needs to be virtual
"virtual" will make compiler check for correct object (w/o always the base class version will be used)
*/
class A_Animal
{
	protected:
		std::string	type;

	public:
		A_Animal(void);//default
		A_Animal(const A_Animal& other); //copy construct
		A_Animal &operator=( const A_Animal& other); //copy assignment
		virtual ~A_Animal(); //destructor 

		virtual void	makeSound(void) const = 0; //pure virtual function, makes class abstract

		const std::string& getType(void) const;
};

#endif