#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: virtual public AMateria
{
	public:
		Ice(std::string const & type);//default
		Ice(const Ice& other); //copy construct
		Ice &operator=( const Ice& other); //copy assignment
		virtual ~Ice(); //destructor

		Ice* clone(void); //returns new cloned instance
		virtual void use(ICharacter& target);

};


#endif