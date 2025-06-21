#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP


#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);//default
		WrongCat(const WrongCat& other); //copy construct
		WrongCat &operator=( const WrongCat& other); //copy assignment
		~WrongCat(); //destructor

		// void	makeSound(void) const;

};

#endif