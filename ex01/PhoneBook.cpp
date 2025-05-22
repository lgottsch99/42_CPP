/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:54:51 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/22 18:12:29 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
class PhoneBook
{
	public:
		Contact people[8];
		int oldest; //index of oldest
		int current;

		PhoneBook();
		void shout();
		void add_contact();

};
*/

//Constructor
PhoneBook::PhoneBook()
{
	oldest = 0;
	current = 0;
}

//method
void PhoneBook::shout()
{
	std::cout << "BOOK IS BOOKING!" << std::endl;
}

void PhoneBook::add_contact()
{
	std::cout << "in phonebook add_contact\n";
	
	//check current, if bigger 8, remove oldest
	//if (current > 7) //7 is last pos in array


	// std::cout << "First Name: ";
	// std::cin >> people[current].first; //CRASH

	// std::cout << "Last Name: ";
	// std::cin >> people[current].last;
	
	// std::cout << "Nickname: ";
	// std::cin >> people[current].nick;

	// std::cout << "Number: ";
	// std::cin >> people[current].number;
	// //TODO check if digits and + only

	// std::cout << "Darkest Secret: ";
	// std::cin >> people[current].secret;

	// current++;

}
