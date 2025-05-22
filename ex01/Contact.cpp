/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:53:03 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/22 18:43:26 by lgottsch         ###   ########.fr       */
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
		bool number;


	public:				//Access specifier
		void shout();	//Method
		void add();
		char *first;	//Member
		char *last;
		char *nick;
		char *number;
		char *secret;
		Contact();		//Constructor

};
*/

Contact::Contact()
{
	is_number = false;
	
	first = "";
	last = "";
	nick = "";
	number = "";
	secret = "";
}

void	Contact::shout()
{
	std::cout << "HELLOOOOOOO" << std::endl;
}

//A saved contact can’t have empty fields.
void	Contact::add()
{

	std::cout << "in Contact add\n";

	std::cout << "\nFirst Name: ";
	std::cin >> first;

	std::cout << "Last Name: ";
	std::cin >> last;
	
	std::cout << "Nickname: ";
	std::cin >> nick;

	//TODO check if digits and + only
	while (is_number == false)
	{
		std::cout << "Number: ";
		std::cin >> number;
		if (number_check(number) != 0) 
		{
			number = "";
			std::cout << "Number can only contain digits 0-9 and +\n";

		}
		else
			is_number = true;
	}

	std::cout << "Darkest Secret: ";
	std::cin >> secret;

	std::cout << std::endl;

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