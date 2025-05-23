/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:53:03 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/23 17:05:58 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

/*
Method: ft that belongs to a class

Constructor: ft that is autom. called when class is created
			-> needs same name as Class!
Member: data inside classes
	Note: By default, all members of a class are private if you don't 
	specify an access specifier!




class Contact
{
	bool is_number;
	bool is_empty;

	public:				//Access specifier
		void shout();	//Method
		void add();
		int	number_check(std::string number);
		
		std::string first;	//Member
		std::string last;
		std::string nick;
		std::string number;
		std::string secret;
		Contact();		//Constructor

};

*/

Contact::Contact()
{
	is_number = false;
	is_empty = true;
	
	first = "";
	last = "";
	nick = "";
	number = "";
	secret = "";
}


//TODO A saved contact can’t have empty fields.
void	Contact::add()
{
	//std::cout << "in Contact add\n";
	std::cout << "\n";

	while (first.empty())
	{
		std::cout << "First Name: ";
		std::getline(std::cin, first);
	}	is_number = false;
	is_empty = true;
	
	while (last.empty())
	{
		std::cout << "Last Name: ";
		std::getline(std::cin, last);
	}
	std::cout << "you entered: " << last << "\n";

	while (nick.empty())
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, nick);
	}
	std::cout << "you entered: " << nick << "\n";


	//TODO check if digits and + only
	while (is_number == false)
	{
		std::cout << "Number: ";
		std::getline(std::cin, number);

		if (number_check(number) != 0) 
		{
			number = "";
			std::cout << "Number can only contain digits 0-9 and +\n";

		}
		else
			is_number = true;
	}

	while (secret.empty())
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, secret);
	}
	std::cout << "you entered: " << secret << "\n";

	is_empty = false;
	std::cout << "\n";

}

int	Contact::number_check(std::string number)
{
	int i;
	int len;

	i = 0;
	len = number.length();
	while (i < len)
	{
		if (number[i] < '0' || number[i] > '9')
		{
			if (number[i] != '+')
				return (1);
		}
		i++;
	}
	return (0);
}

void	Contact::clear_contact()
{
	is_number = false;
	is_empty = true;
	
	first = "";
	last = "";
	nick = "";
	number = "";
	secret = "";
}