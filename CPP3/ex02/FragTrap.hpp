

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap( std::string name);//default
		FragTrap(const FragTrap& other); //copy construct
		FragTrap &operator=( const FragTrap& other); //copy assignment
		~FragTrap(); //destructor

		void attack(const std::string& target);//override to print own msg
		void highFivesGuys(void);
};


#endif