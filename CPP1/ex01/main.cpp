/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:30:43 by Watanudon         #+#    #+#             */
/*   Updated: 2025/06/03 12:21:29 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name );

int main (void)
{
	Zombie *horde;
	int		N;
	int		i;

	N = 5;
	horde = NULL;
	horde = zombieHorde(N, "sybille");


	std::cout << "\n**back in main**\n";
	
	i = 0;
	while (i < N)
		horde[i++].announce();
	
	delete [] horde;
	
	return 0;
}