
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>


class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
		int			_HitPoints;
		int			_EnergyPoints;
		int			_AttackDamage;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);//default
		DiamondTrap(const DiamondTrap& other); //copy construct
		DiamondTrap &operator=(const DiamondTrap& other); //copy assignment
		~DiamondTrap(); //destructor

		using ScavTrap::attack;
		void	whoAmI();
		void	print_stat();
};

#endif