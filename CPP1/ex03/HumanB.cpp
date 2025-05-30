/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:38:32 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/30 14:21:56 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB( std::string name ):
	_Weapon(NULL), _name (name)
{
	return;
}

HumanB::~HumanB()
{
	_name.clear();
}

void	HumanB::attack()
{
	std::cout << _name << " attacks with their " << _Weapon->getType() << "\n";
}
void	HumanB::setWeapon( Weapon& og )
{
	_Weapon = &og;
	return ;
}
