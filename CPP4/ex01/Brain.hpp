#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
/*
Destructor needs to be virtual
"virtual" will make compiler check for correct object (w/o always the base class version will be used)
*/
class Brain
{
	protected:
		std::string	ideas[100];

	public:
		Brain(void);//default
		Brain(const Brain& other); //copy construct
		Brain &operator=( const Brain& other); //copy assignment
		virtual ~Brain(); //destructor 

		void	set_idea(int index, std::string idea);
		void	print_idea(int index);

};

#endif