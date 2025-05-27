/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:53:03 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/27 15:35:21 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	_is_number = false;
	is_empty = true;
	
	first = "";
	last = "";
	nick = "";
	number = "";
	secret = "";
}

Contact::~Contact()
{
	clear_contact();
}

/*getting line of input in CTRL D safe manner
*/
int	Contact::_get_input(std::string *str)
{
	if (!std::getline(std::cin, *str))
	{
		std::cout << "\nEOF or other Error detected" << std::endl;
		std::cin.clear();
		return 1;
	}
	return 0;
}

int	Contact::add()
{
	std::cout << "\n";

	while (first.empty())
	{
		std::cout << "First Name: ";
		if (_get_input(&first) == 1)
			return 1;
	}
	
	while (last.empty())
	{
		std::cout << "Last Name: ";
		if (_get_input(&last) == 1)
			return 1;
	}

	while (nick.empty())
	{
		std::cout << "Nickname: ";
		if (_get_input(&nick) == 1)
			return 1;
	}

	while (_is_number == false || number.empty())
	{
		std::cout << "Number: ";
		if (_get_input(&number) == 1)
			return 1;

		if (_number_check(number) != 0) 
		{
			number.clear();
			std::cout << "Number can only contain digits 0-9 and +\n";
		}
		else
			_is_number = true;
	}

	while (secret.empty())
	{
		std::cout << "Darkest Secret: ";
		if (_get_input(&secret) == 1)
			return 1;

	}

	is_empty = false;
	std::cout << "\n";
	return 0;
}

int	Contact::_number_check(std::string number) const
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
	_is_number = false;
	is_empty = true;
	
	first.clear();
	last.clear();
	nick.clear();
	number.clear();
	secret.clear();
}

void	Contact::display_contact() const
{
	int	width;

	width = 25;
	std::cout.setf(std::ios::left);
	
	std::cout.width(width);
	std::cout.fill(' ');
	std::cout << "First Name: ";
	std::cout << first << "\n";

	std::cout.width(width);
	std::cout << "Last Name: ";
	std::cout << last << "\n";

	std::cout.width(width);
	std::cout << "Nickname: ";
	std::cout << nick << "\n";

	std::cout.width(width);
	std::cout << "Number: ";
	std::cout << number << "\n";

	std::cout.width(width);
	std::cout << "Darkest Secret: ";
	std::cout << secret << "\n\n";

	std::cout.unsetf(std::ios::left);
}
