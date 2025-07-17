
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
	std::cout << "ScavTrap " << this->getName() << " is now in Gate Keeper mode!\n";
}


void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		ScavTrap::_displayMsgAttack(target);

		//reduce energy
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else
		std::cout << "ScavTrap " << this->getName() << " has not enough energy or hit points to attack!\n";
}

void	ScavTrap::_displayMsgAttack(const std::string& target)
{
	std::cout << "ScavTrap " << this->getName() << " attacks " << target
	<< ", causing " << this->getAttackDamage() << " points of damage!\n";
}