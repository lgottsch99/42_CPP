/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:25:09 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/30 12:17:33 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
/*
Reference: Alias to existing var (ptr stores mem adress)
	-> pointer to a var (it CANNNNN change the var)

	can never be unititialized, must always refer to an object
	no dereferencing necessary, can be used like a normal var
	can never be void
	cannot perfrom arithmetic operations (++ / --)
	can not be RESET (or changed to "point" to other var)

	=> references are SAFER than ptr and a bit EASIER

*/

int main (void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	//print mem address of str 
	std::cout << &str << "\n";

	//print mem add held by strPTR
	std::cout << stringPTR << "\n";

	//print mem add held by stringREF
	std::cout << &stringREF << "\n";


	//print values
	std::cout << str << "\n";

	std::cout << *stringPTR << "\n";

	std::cout << stringREF << "\n";

	return 0;
}