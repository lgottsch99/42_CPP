#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal(void);//default
		WrongAnimal(const WrongAnimal& other); //copy construct
		WrongAnimal &operator=( const WrongAnimal& other); //copy assignment
		~WrongAnimal(); //destructor 

		void	makeSound(void) const; 

		const std::string& getType(void) const;

};

#endif