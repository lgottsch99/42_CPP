
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

//CONSTRUCTORS, DESTRUCTOR ------------------

//default constructor
FragTrap::FragTrap( std::string name ): 
ClapTrap(name)
{
	std::cout << "FragTrap Default constructor (string) called\n";
	
	//need to update values as wanted for FragTrap
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

//copy constr
FragTrap::FragTrap(const FragTrap& other):
ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called\n";
}

//copy assignement
FragTrap &FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Copy assignment operator called\n";
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

//destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called\n";
}


void FragTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "FragTrap " << this->getName() << " attacks " << target
		<< ", causing " << this->getAttackDamage() << " points of damage!\n";
	
		//reduce energy
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else
		std::cout << "FragTrap " << this->getName() << " has not enough energy or hit points to attack!\n";
}


void FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << ": HIGH FIVES GUYS!!\n";
}
