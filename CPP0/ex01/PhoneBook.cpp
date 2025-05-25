/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:54:51 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/24 15:53:13 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


/*writes padded text field for phonebook entry overview
*/
void	PhoneBook::_padded_field(std::string str) const
{
	if (str.length() >= 10)
	{
		std::cout.write(str.c_str(), 9);
		std::cout << ".";
	}
	else
	{
		std::cout.setf(std::ios::right);
		std::cout.width(10);
		std::cout.fill('.');
		std::cout << str;
		std::cout.unsetf(std::ios::right);
	}
}

/* display all saved contacts as (index | first | last | nick)
*/
void	PhoneBook::show_saved_contacts() const
{
	int	index;

	index = 0;
	while (index < 8 && !people[index].first.empty())
	{
		std::cout.setf(std::ios::right);
		std::cout.width(10);
		std::cout.fill('.');

		//1. index (range 0-7)
		std::cout << index << "|";

		//2. any other field
		_padded_field(people[index].first);
		std::cout << "|";
		_padded_field(people[index].last);
		std::cout << "|";
		_padded_field(people[index].nick);
		std::cout << "\n";

		index++;
	}
}
