
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"


class ScavTrap: public ClapTrap
{
	private:
		void	_displayMsgAttack(const std::string& target);

	public:
		ScavTrap( std::string name);//default
		ScavTrap(const ScavTrap& other); //copy construct
		ScavTrap &operator=( const ScavTrap& other); //copy assignment
		~ScavTrap(); //destructor

		void attack(const std::string& target);//override to print own msg
		void guardGate(void);
};

#endif
