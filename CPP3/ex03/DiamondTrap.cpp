


#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
ClapTrap("none_clap_name"), ScavTrap("none"), FragTrap("none")
{
	std::cout << "DiamondTrap Default constructor (void) called\n";
	
	//need to update values as wanted for DiamondTrap
	_name = "none";
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 30;
}



//default constructor
DiamondTrap::DiamondTrap(std::string name):
ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap Default constructor (string) called\n";
	
	//need to update values as wanted for DiamondTrap (as here clap is virtual, scav and frag dont actually init or touch it, need to set value here / ord efine special default  get set)
	_name = name;
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 30;
}

//copy constr
DiamondTrap::DiamondTrap(const DiamondTrap& other):
ClapTrap(other._name + "_clap_name"), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap Copy constructor called\n";

	_name = other._name;
	_HitPoints = other._HitPoints;
	_EnergyPoints = other._EnergyPoints;
	_AttackDamage = other._AttackDamage;
}

//copy assignement
DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap Copy assignment operator called\n";
	if (this != &other)
	{
		_name = other._name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
	}
	return (*this);
}

//destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called\n";
}


void DiamondTrap::whoAmI(void)
{
	std::cout << "My name: " << this->_name << "\n"
		<< "My ClapTrap name: " << ClapTrap::getName() << "\n";
}


void	DiamondTrap::print_stat(void)
{
	std::cout << _name << "\n"
	<< "hit points:    " << _HitPoints << "\n"
	<< "energy points: "<< _EnergyPoints << "\n"
	<< "attack damage: "<< _AttackDamage << "\n\n";
}
