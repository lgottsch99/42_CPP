
#include "ClapTrap.hpp"

//CONSTRUCTORS, DESTRUCTOR ------------------

ClapTrap::ClapTrap( void ): 
_name("none"),_HitPoints(10), _EnergyPoints(10), _AttackDamage(10)
{
	std::cout << "Default constructor (void) called\n";
}

//default constructor
ClapTrap::ClapTrap( std::string name ): 
_name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(10)
{
	std::cout << "Default constructor (string) called\n";
}

//copy constr
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called\n";
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAttackDamage(other.getAttackDamage());
}

//copy assignement
ClapTrap &ClapTrap::operator=( const ClapTrap& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());	
	}
	return (*this);
}

//destructor
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}


// GETTERS, SETTERS ------------------

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

void		ClapTrap::setName(std::string name)
{
	this->_name = name;
}

int			ClapTrap::getHitPoints(void) const
{
	return (this->_HitPoints);
}

void		ClapTrap::setHitPoints(int num)
{
	this->_HitPoints = num;
}

int			ClapTrap::getEnergyPoints(void) const
{
	return (this->_EnergyPoints);
}

void		ClapTrap::setEnergyPoints(int num)
{
	this->_EnergyPoints = num;
}

int			ClapTrap::getAttackDamage(void) const
{
	return (this->_AttackDamage);
}

void		ClapTrap::setAttackDamage(int num)
{
	this->_AttackDamage = num;
}


//MEMBER FTs ------------------

void ClapTrap::attack(const std::string& target) //??? string -> dummy only
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target
		<< ", causing " << this->getAttackDamage() << " points of damage!\n";

		//reduce energy
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else
		std::cout << "ClapTrap " << this->getName() << " has not enough energy or hit points to attack!\n";
}


void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage!\n";
	this->setHitPoints(this->getHitPoints() - amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "ClapTrap " << this->getName() << " repairs itself by adding "
			<< amount << " Hit Points!\n";

		//reduce energy
		this->setEnergyPoints(this->getEnergyPoints() - 1);

		//repair
		this->setHitPoints(this->getHitPoints() + amount);
	}
	else
		std::cout << "ClapTrap " << this->getName() << " has not enough energy or hit points to repair!\n";

}
