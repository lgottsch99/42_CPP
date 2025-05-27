/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Watanudon <Watanudon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:31:35 by Watanudon         #+#    #+#             */
/*   Updated: 2025/05/27 22:47:53 by Watanudon        ###   ########.fr       */
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
	//malloc memory ONLY
	newHorde = new Zombie[N];
	//init as zombie object
	while (i < N)
	{
		newHorde[i] = Zombie(name);
		i++;
	}
	return (newHorde);	
}