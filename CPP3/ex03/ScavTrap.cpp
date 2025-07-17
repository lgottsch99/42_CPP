
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

//CONSTRUCTORS, DESTRUCTOR ------------------

//default constructor
ScavTrap::ScavTrap( std::string name ): 
ClapTrap(name)
{
	std::cout << "ScavTrap Default constructor (string) called\n";
	
	//need to update values as wanted for ScavTrap
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
}

//copy constr
ScavTrap::ScavTrap(const ScavTrap& other):
ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called\n";
}

//copy assignement
ScavTrap &ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy assignment operator called\n";
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

//destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called\n";
}


void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode!\n";
}


void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_AttackDamage << " points of damage!\n";	

		//reduce energy
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else
		std::cout << "ScavTrap " << this->_name << " has not enough energy or hit points to attack!\n";
}
