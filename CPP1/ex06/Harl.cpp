/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:30:42 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/31 17:18:18 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::_debug( void )
{
	std::cout << "[ DEBUG ]\n";
	// std::cout << "Debug: " << "\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void	Harl::_info( void )
{
	std::cout << "[ INFO ]\n";
	// std::cout << "Info: " << "\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::_warning( void )
{
	std::cout << "[ WARNING ]\n";
	// std::cout << "Warning: " << "\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}

void	Harl::_error( void )
{
	std::cout << "[ ERROR ]\n";
	// std::cout << "Error: " << "\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::_other( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]\n";
	// std::cout << "Other: " << "\n";
	// std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}


void	Harl::complain( std::string level )
{
	void (Harl::*ptrs[5])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error, &Harl::_other};
	std::string array[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "OTHER"};
	int i = 0;

	while (i < 5)
	{
		if (array[i] == level)
			break;
		i++;
	}

	/* WITHOUT BREAK:
		ONCE a case matches, all the following cases get executed too!!
	
	switch (char) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		std::cout << "It's a vowel!\n";
		break;
}
	*/
	switch (i)
	{
		case 0: //DEBUG
			(this->*ptrs[0])();
			std::cout << "\n";
			// (this->*ptrs[1])();
			// std::cout << "\n";
			// (this->*ptrs[2])();
			// std::cout << "\n";
			// (this->*ptrs[3])();
			// std::cout << "\n";
			// break;

		case 1: //INFO
			(this->*ptrs[1])();
			std::cout << "\n";
			// (this->*ptrs[2])();
			// std::cout << "\n";
			// (this->*ptrs[3])();
			// std::cout << "\n";
			// break;

		case 2: //WARNING
			(this->*ptrs[2])();
			std::cout << "\n";
			// (this->*ptrs[3])();
			// std::cout << "\n";
			// break;

		case 3: //ERROR
			(this->*ptrs[3])();
			std::cout << "\n";
			break; //to stop the fallthrough

		//------------------------
		case 5: //OTHER
			(this->*ptrs[4])();
			std::cout << "\n";
			// break;

	}
	return ;
}

