/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:01:29 by lgottsch          #+#    #+#             */
/*   Updated: 2025/06/03 12:15:28 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"


//This function creates a zombie, names it, and returns it so you can use it outside
//of the function scope. 
// ->alloced 
Zombie* newZombie( std::string name );

//This function creates a zombie, names it, and makes it announce itself.
// -> on stack
void randomChump( std::string name );


int main (void)
{
	Zombie	*a;
	Zombie	*b;

	a = newZombie("Bernd"); //using new to dyn. alloc + construct
	b = newZombie("Ralf");

	randomChump("Fritz");

	std::cout << "\n**back in main function**\n";
	
	delete a; //"freeing" with delete
	delete b;

	return 0;
}