

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	print_stat(ClapTrap& name)
{
	std::cout << name.getName() << "\n"
	<< "hit points:    " << name.getHitPoints() << "\n"
	<< "energy points: "<< name.getEnergyPoints() << "\n"
	<< "attack damage: "<< name.getAttackDamage()<< "\n\n";
}

int main(void)
{
	ClapTrap Frank("Frank");
	ScavTrap Lucy("Lucy");
	FragTrap Moni("Moni");

	//check init
	std::cout << "At start:\n"; 
	print_stat(Frank);
	print_stat(Lucy);
	print_stat(Moni);

	//attack
	Frank.attack("AIR");
	Lucy.attack("CLOUD");
	Moni.attack("BIRD");
	print_stat(Frank);
	print_stat(Lucy);

	Lucy.guardGate();
	Moni.highFivesGuys();


	//set energy to 0
	Frank.setEnergyPoints(0);
	Lucy.setEnergyPoints(0);
	Moni.setEnergyPoints(0);
	print_stat(Frank);
	print_stat(Lucy);
	print_stat(Moni);

	//try doing sth with 0 energy
	Frank.beRepaired(10);
	Lucy.beRepaired(10);
	Moni.beRepaired(10);

	return (0);
}