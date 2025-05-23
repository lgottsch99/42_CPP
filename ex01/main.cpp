/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:13:26 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/23 20:29:47 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "Contact.hpp"

/* TODO
Streams (handle ctrl d after getting user input)
	ctrl d = EOF

std::endl flushes buffer -> slower, use \n if only need a line break


????

*/




void	search(PhoneBook *pbook)
{
	std::string	str_index;
	int			i_index;
	bool		valid_index;

	valid_index = false;
	i_index = -1;
	
	//check if ANY entries exist
	if (pbook->people[0].first.empty())
	{
		std::cout << "Phonebook has no entries yet!\n";
		return;
	}


	// display all saved contacts
	pbook->show_saved_contacts();
	std::cout << "\n";

	//prompt for index to display
	while (!valid_index)
	{
		std::cout << "Enter Contact-Index: ";
		std::getline(std::cin, str_index);
		i_index = atoi(str_index.c_str());

		std::cout << "Entered: " << i_index << "\n";
		
		//check if index valid
		if (i_index >= 0 && i_index <= 7)
		{
			if (pbook->people[i_index].first.empty())
				std::cout << "Contact Nr. " << i_index << " does not exist.\n";
			else
				valid_index = true;
		}
		else
			std::cout << "Index out of valid range (0-7).\n";
	}

	//display all info of contact
	if (valid_index)
		pbook->people[i_index].display_contact();
	
	return ;
}

void	add_contact(int *current, PhoneBook *pbook)
{
	if (*current == 8)
		*current = 0;

	//check if contact is empty, else remove everything
	if (pbook->people[*current].is_empty == false)
		pbook->people[*current].clear_contact();

	std::cout << "current index: " << *current << "\n";
	
	//Prompt and add new contact
	pbook->people[*current].add(); //OK

}


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
		std::getline(std::cin, command);
		
		if (command.compare("ADD") == 0)
		{
			add_contact(&current, &pbook);
			current++;
		}
		else if (command.compare("SEARCH") == 0)
		{
			std::cout << "SEARCH detected\n";
			search(&pbook);
		}
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "EXIT detected\n";
			//exit
				//clear memory?
		}
		else
		{
			std::cout << "Invalid command. Use ADD, SEARCH or EXIT!" << std::endl;
		}
	}

}