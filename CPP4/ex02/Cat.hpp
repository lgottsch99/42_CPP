
#ifndef CAT_HPP
#define CAT_HPP

#include "A_Animal.hpp"
#include "Brain.hpp"

class Cat: virtual public A_Animal
{
	private:
		Brain *brain;

	public:
		Cat(void);//default
		Cat(const Cat& other); //copy construct
		Cat &operator=( const Cat& other); //copy assignment
		~Cat(); //destructor

		void	makeSound(void) const;
		void	set_idea(int index, std::string idea);
		void	print_idea(int index);

};


#endif