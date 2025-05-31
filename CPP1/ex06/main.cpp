/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newmain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:39:33 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/31 16:55:39 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"
#include <iostream>


/* Use of SWITCH !

switch in c++:
	switch (expression) {
		case 'a':
			do sth
			....
			(break;)
			
		default:

	}

	->expression needs to be int or char!!!!!
	->no double cases
	-> break is optional
	
*/

int main (int argc, char *argv[])
{
	Harl		harl;
	std::string	input;
	int			i;

	i = -1;
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <level>\n";
		return 1;
	}

	input = argv[1];
	harl.complain(input);


	return 0;
}