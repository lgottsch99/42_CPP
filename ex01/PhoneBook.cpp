/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:54:51 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/23 20:24:34 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
class PhoneBook
{
	public:
		Contact people[8];
		void	show_saved_contacts();

		PhoneBook();

};
*/


//writes padded text field for phonebook entry overview
void	PhoneBook::padded_field(std::string str)
{
	if (str.length() >= 10) //OK
	{
		std::cout.write(str.c_str(), 9);
		std::cout << ".";
	}
	else//OK
	{
		std::cout.setf(std::ios::right);
		std::cout.width(10);
		std::cout.fill('.');
		std::cout << str;
		std::cout.unsetf(std::ios::right);
	}
}

//method
void	PhoneBook::show_saved_contacts()
{
	int	index;

	index = 0;
	// display all saved contacts as (index | first | las | nick)
	while (index < 8 && !people[index].first.empty())
	{
		std::cout.setf(std::ios::right);
		std::cout.width(10);
		std::cout.fill('.');

		//1. index (range 0-7)
		std::cout << index << "|";

		//2. any other field
		padded_field(people[index].first);
		std::cout << "|";
		padded_field(people[index].last);
		std::cout << "|";
		padded_field(people[index].nick);
		std::cout << "\n";

		index++;
	}
}