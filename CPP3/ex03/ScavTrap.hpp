
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap( std::string name);//default
		ScavTrap(const ScavTrap& other); //copy construct
		ScavTrap &operator=( const ScavTrap& other); //copy assignment
		~ScavTrap(); //destructor

		virtual void attack(const std::string& target);//override to print own msg
		void guardGate(void);
};

#endif
