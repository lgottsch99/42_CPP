/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Watanudon <Watanudon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:52:48 by Watanudon         #+#    #+#             */
/*   Updated: 2025/05/27 22:34:00 by Watanudon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"

//malloced version

Zombie* newZombie( std::string name )
{
	Zombie	*newZombie;

	newZombie = NULL;
	newZombie = new (std::nothrow) Zombie(name); //nothrow prevents exception on malloc failure, instead nullptr returned
	if (!newZombie)
		std::cout << "dynamic allocation failed!" << std::endl;
	return (newZombie);
	
}
