/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:58:14 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/31 16:39:29 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>


/* Use of SWITCH !

(only c11)
clean way of handling switch + strings: 
https://medium.com/@ryan_forrester_/using-switch-statements-with-strings-in-c-a-complete-guide-efa12f64a59d 


switch in c++:
	switch (expression) {
		case 'a':
			do sth
			....
			(break;)
			
		default:

	}

	->expression needs to be int or char!!!!!
	->no double cases
	-> break is optional
	
*/

enum class Level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	OTHER
};

Level decide_case(std::string& input)
{
	if (input == "DEBUG")
		return Level::DEBUG;
	else if (input == "INFO")
		return Level::INFO;
	else if (input == "WARNING")
		return Level::WARNING;
	else if (input == "ERROR")
		return Level::ERROR;
	else
		return Level::OTHER;
}

//TODO: add switch logic INSIDE HARL not main!!!
int main (int argc, char *argv[])
{
	Harl		harl;
	enum Level	level;
	std::string	input;
	int			i;

	i = -1;
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <level>\n";
		return 1;
	}

	input = argv[1];

	//switch to decide number of errors to print? 
	switch (decide_case(input))
	{
		case Level::OTHER:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;

		case Level::DEBUG:
			harl.complain("WARNING");
			std::cout << "\n";
			harl.complain("ERROR");
			std::cout << "\n";
			harl.complain("INFO");
			std::cout << "\n";
			harl.complain("DEBUG");
			std::cout << "\n";
			break;

		case Level::INFO:
			harl.complain("WARNING");
			std::cout << "\n";
			harl.complain("ERROR");
			std::cout << "\n";
			harl.complain("INFO");
			std::cout << "\n";
			break;
			
		case Level::WARNING:
			harl.complain("WARNING");
			std::cout << "\n";
			harl.complain("ERROR");
			std::cout << "\n";
			break;

		case Level::ERROR:
			harl.complain("ERROR");
			std::cout << "\n";
			break;

	}








	// //somehow assign strings to enum? (maybe using switch)
	// if (input.compare("DEBUG") == 0)
	// 	i = DEBUG;
	// else if (input.compare("INFO") == 0)
	// 	i = INFO;
	// else if (input.compare("WARNING") == 0)
	// 	i = WARNING;
	// else if (input.compare("ERROR") == 0)
	// 	i = ERROR;
	// else
	// 	i = OTHER;

	// //execute according to case
	// switch (i)
	// {
	// 	case OTHER: //only other
	// 		std::cout << "[ Probably complaining about insignificant problems ]\n";
	// 		break;

	// 	case ERROR: //only error
	// 		harl.complain("ERROR");

	// 	case WARNING:
	// 		harl.complain("WARNING");
	// 		std::cout << "\n";
	// 		harl.complain("ERROR");
	// 		std::cout << "\n";
	// 		break;

	// 	case INFO:
	// 		harl.complain("WARNING");
	// 		std::cout << "\n";
	// 		harl.complain("ERROR");
	// 		std::cout << "\n";
	// 		harl.complain("INFO");
	// 		std::cout << "\n";

	// 	case DEBUG:
	// 		harl.complain("WARNING");
	// 		std::cout << "\n";
	// 		harl.complain("ERROR");
	// 		std::cout << "\n";
	// 		harl.complain("INFO");
	// 		std::cout << "\n";
	// 		harl.complain("DEBUG");
	// 		std::cout << "\n";
	// }
	return 0;
}
