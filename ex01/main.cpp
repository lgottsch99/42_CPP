/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:13:26 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/22 18:51:46 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

/* TODO
Streams (handle ctrl d after getting user input)

*/

int main()
{
	PhoneBook	pbook;
	std::string command;

	bool		exit;
	int current = 0;

	exit = false;

	//prompt command (ADD SEARCH EXIT)
	while (exit == false)
	{
		//prompt for cmd ADD, SEARCH or EXIT
		std::cout << "Enter command (ADD / SEARCH / EXIT): ";
		std::cin >> command;
		
		if (command.compare("ADD") == 0)
		{
			//add_contact()
			if (current == 8)
				current = 0;
			pbook.people[current].add(); //OK
			current++;
		}
		else if (command.compare("SEARCH") == 0)
		{
			std::cout << "SEARCH detected\n";
			//search
		}
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "EXIT detected\n";
			//exit
		}
		else
			std::cout << "Invalid command. Use ADD, SEARCH or EXIT!\n";
	}

}