/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:58:26 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/22 18:33:03 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	bool is_number;

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

#endif