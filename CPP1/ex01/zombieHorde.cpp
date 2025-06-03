/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:31:35 by Watanudon         #+#    #+#             */
/*   Updated: 2025/06/03 12:21:44 by lgottsch         ###   ########.fr       */
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
	newHorde = new Zombie[N]; //if allocating array: NO PASSING OF PARAMS POSSIBLE!! need to init later
	
	i = 0;
	while (i < N)
	{
		newHorde[i].setname(name);
		i++;
	}
	return (newHorde);	
}