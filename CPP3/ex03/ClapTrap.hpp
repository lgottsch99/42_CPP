
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_HitPoints; //health of claptrap
		int			_EnergyPoints;
		int			_AttackDamage;
		void	_displayMsgAttack(const std::string& target);

	public:
		ClapTrap(void);
		ClapTrap(std::string name); //default
		ClapTrap(const ClapTrap& other); //copy construct
		ClapTrap &operator=( const ClapTrap& other); //copy assignment
		~ClapTrap(); //destructor

		//getters, setters
		std::string getName(void) const;
		void		setName(std::string name);

		int			getHitPoints(void) const;
		void		setHitPoints(int num);

		int			getEnergyPoints(void) const;
		void		setEnergyPoints(int num);

		int			getAttackDamage(void) const;
		void		setAttackDamage(int num);

		//member fts
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};


#endif
