

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

void	print_stat(ClapTrap& name)
{
	std::cout << name.getName() << "\n"
	<< "hit points:    " << name.getHitPoints() << "\n"
	<< "energy points: "<< name.getEnergyPoints() << "\n"
	<< "attack amage:  "<< name.getAttackDamage()<< "\n\n";
}

int main(void)
{
	ClapTrap Frank("Frank");
	ClapTrap Fritz = Frank;
	// ClapTrap Bro;
	// Bro = Fritz;


	std::cout << "At start:\n"; 
	print_stat(Frank);

	Frank.attack("AIR");
	print_stat(Frank);

	Frank.setAttackDamage(2);
	Frank.attack("ITSELF");
	print_stat(Frank);

	Frank.takeDamage(4);
	print_stat(Frank);

	Frank.takeDamage(4);
	print_stat(Frank);

	Frank.beRepaired(12);
	print_stat(Frank);

	Frank.setEnergyPoints(0);
	print_stat(Frank);

	Frank.attack("ITSELF");
	Frank.beRepaired(12);

	return (0);
}