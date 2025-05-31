/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:53:54 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/31 14:50:51 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>


/*
Harl needs to complain a lot -> all levels including above?
so eg level info: debgu + info?
or single level only?
*/


int main (void)
{
	Harl 		harl;

	std::cout << "\nLevel is DEBUG:\n";
	harl.complain("DEBUG");

	std::cout << "\nLevel is INFO:\n";
	harl.complain("INFO");

	std::cout << "\nLevel is WARNING:\n";
	harl.complain("WARNING");


	std::cout << "\nLevel is ERROR:\n";
	harl.complain("ERROR");

	std::cout << "\nEdge Cases:\n";
	harl.complain("");
	harl.complain("lol");
	
	return 0;
}

