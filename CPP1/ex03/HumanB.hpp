/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:38:01 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/30 14:23:16 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"


/*
Take weapon by ptr!!!!
pass by reference (otherwose copy is created, later pointer to copy, then copy gets destroyed bc out of ft scope)
*/

class HumanB
{
	private:
		Weapon		*_Weapon;
		std::string _name;

	public:
		HumanB( std::string name );
		~HumanB();

		void	attack( void );
		void	setWeapon( Weapon& weapon );  //need to pass as reference, or else we assign ptr to copy!
};


#endif