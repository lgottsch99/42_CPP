/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:31:35 by Watanudon         #+#    #+#             */
/*   Updated: 2025/05/29 17:22:49 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*newHorde;
	int		i;

	newHorde = NULL;
	newHorde = new Zombie[N]; //if allocating array: NO PASSING OF PARAMS POSSIBLE!! need to init laters
	i = 0;
	while (i < N)
	{
		newHorde[i].announce(); //before naming
		newHorde[i].setname(name);
		newHorde[i].announce(); //after nameing
		i++;
	}
	return (newHorde);	
}