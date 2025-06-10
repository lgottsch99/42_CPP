

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap Pete("Pete");
	DiamondTrap Bernd = Pete;
	DiamondTrap Bro;
	Bro = Pete;

	//check init
	std::cout << "\nAt start:\n"; 
	Pete.print_stat();
	Bernd.print_stat();
	Bro.print_stat();

	//inherited special fts
	Pete.attack("STONE");
	Pete.highFivesGuys();
	Pete.guardGate();

	//check names
	Pete.whoAmI();
	Bernd.whoAmI();
	Bro.whoAmI();

	std::cout << "\n\n";

	return (0);
}