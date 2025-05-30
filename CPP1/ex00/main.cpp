/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:01:29 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/29 12:38:10 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"


//TODO: decide which of the function malloc aand which not

//This function creates a zombie, names it, and returns it so you can use it outside
//of the function scope. 
// ->malloced 
Zombie* newZombie( std::string name );

//This function creates a zombie, names it, and makes it announce itself.
void randomChump( std::string name );


int main (void)
{
	std::string		fritz = "Fritz";
	std::string		bernd = "Bernd";
	std::string		ralf = "Ralf";

	Zombie	*a;
	Zombie	*b;

	a = newZombie(bernd); //using new to dyn. alloc + construct
	b = newZombie(ralf);

	delete b;
	
	randomChump(fritz); // allocated on stack so destroyed autom.

	delete a; //"freeing" with delete
	
	return 0;
}