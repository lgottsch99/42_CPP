/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:37:33 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/30 13:55:46 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

/*
Take weapon by REFERENCE!!!!
*/

class HumanA
{
	private:
		Weapon&		_Weapon;
		std::string _name;

	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA();

		void	attack( void );
};


#endif