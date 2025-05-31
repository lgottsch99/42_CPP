/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:30:42 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/31 14:48:08 by lgottsch         ###   ########.fr       */
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
	// std::cout << "Debug: " << "\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void	Harl::_info( void )
{
	// std::cout << "Info: " << "\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::_warning( void )
{
	// std::cout << "Warning: " << "\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}

void	Harl::_error( void )
{
	// std::cout << "Error: " << "\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain( std::string level )
{
	void (Harl::*ptrs[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (array[i] == level)
		{
			(this->*ptrs[i])();
			return;
		}
	}
	std::cout << "Other: Grmpf\n";
	return ;
}

/* USE FUNCTION POINTER TO MEMBER FTs (NO IF ELSE FOREST)*/
// void	Harl::complain( std::string level ) // -> works  but too many if else
// {
// 	//declaration
// 	void (Harl::*debug)(void);
// 	void (Harl::*info)(void);
// 	void (Harl::*warning)(void);
// 	void (Harl::*error)(void);

// 	//assign functions to pointers 
// 	debug = &Harl::_debug;
// 	info = &Harl::_info;
// 	warning = &Harl::_warning;
// 	error = &Harl::_error;

// 	if (level.compare("DEBUG") == 0)
// 	{
// 		//execute
// 		(this->*debug)();
// 	}
// 	else if (level.compare("INFO") == 0)
// 	{
// 		(this->*debug)();
// 		(this->*info)();
// 	}
// 	else if (level.compare("WARNING") == 0)
// 	{
// 		(this->*debug)();
// 		(this->*info)();
// 		(this->*warning)();
// 	}
// 	else if (level.compare("ERROR") == 0)
// 	{
// 		(this->*debug)();
// 		(this->*info)();
// 		(this->*warning)();
// 		(this->*error)();
// 	}
// 	else
// 		std::cout << "Invalid Harl level\n";
// }
