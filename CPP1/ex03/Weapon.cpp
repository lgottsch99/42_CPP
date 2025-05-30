/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:20:39 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/30 14:05:22 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon( std::string type ): 
	_type(type)
{
	return;
}

Weapon::~Weapon()
{
	_type.clear();
	return;
}

std::string& Weapon::getType()
{
	std::string &ref = _type;
	return (ref);
}

void	Weapon::setType( std::string str )
{
	_type.clear();
	_type = str;
	return; 
}
