/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Watanudon <Watanudon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:13:26 by lgottsch          #+#    #+#             */
/*   Updated: 2025/07/11 13:58:49 by Watanudon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "Contact.hpp"

/* getting input in CTRL D safe way
*/
int	get_input(std::string *str)
{
	if (!std::getline(std::cin, *str))
	{
		std::cout << "\nEOF or other Error detected" << std::endl;
		std::cin.clear();
		return 1;
	}
	return 0;
}
/* returns -1 if invalid, index (0-7) if valid
*/
int validity_check(std::string *index)
{
	char c;
	
	//check if index only single char + between 0-7
	if (index->length() != 1)
		return -1;
	
	c = index->at(0);
	if (c >= '0' && c <= '7')
		return (std::atoi(&c));
	return -1;
}

/* prompting for index and showing contact 
*/
int	search_display(PhoneBook *pbook)
{
	std::string	str_index;
	int			i_index;

	i_index = -1;
	while (1)
	{
		std::cout << "Enter Contact-Index: ";
		if (get_input(&str_index) == 1)
		{
			str_index.clear();
			return 1;
		}

		//check if index valid
		i_index = validity_check(&str_index);
		if (i_index != -1)
		{
			if (pbook->people[i_index].first.empty())
				std::cout << "Contact Nr. " << i_index << " does not exist.\n";
			else
			{
				pbook->people[i_index].display_contact();
				break;
			}
		}
		else
			std::cout << "Index invalid (range 0-7).\n";
	}
	str_index.clear();
	return 0;
}


int	search(PhoneBook *pbook)
{
	//check if ANY entries exist
	if (pbook->people[0].first.empty())
	{
		std::cout << "Phonebook has no entries yet!\n";
		return 0;
	}

	//display all saved contacts
	pbook->show_saved_contacts();
	std::cout << "\n";

	return (search_display(pbook));
}

void	add_contact(int *current, PhoneBook *pbook)
{
	if (*current == 8)
		*current = 0;

	//check if contact is empty, else remove existing
	if (pbook->people[*current].is_empty == false)
		pbook->people[*current].clear_contact();
	
	//Add new contact
	pbook->people[*current].add();
}

int main()
{
	PhoneBook	pbook;
	std::string command;
	int			current;

	current = 0;
	while (1)
	{
		std::cout << "Enter command (ADD / SEARCH / EXIT): ";
		if (get_input(&command) == 1)
		{
			command.clear();
			return 1;
		}	
		if (command.compare("ADD") == 0)
		{
			add_contact(&current, &pbook);
			current++;
		}
		else if (command.compare("SEARCH") == 0)
			search(&pbook);
		else if (command.compare("EXIT") == 0)
		{			
			command.clear();
			return 0;
		}
		else
			std::cout << "Invalid command. Use ADD, SEARCH or EXIT!" << std::endl;
	}
}
