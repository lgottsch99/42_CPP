/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:38:15 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/30 14:21:00 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanA::HumanA( std::string name, Weapon& weapon ):
	_Weapon( weapon ), _name( name )
{
	return;
}

HumanA::~HumanA()
{
	_name.clear();
}

void	HumanA::attack( void )
{
	std::cout << _name << " attacks with their " << _Weapon.getType() << "\n";
}