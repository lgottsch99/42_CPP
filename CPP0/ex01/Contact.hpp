/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:58:26 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/24 15:51:55 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		bool	_is_number;

		int		_get_input(std::string *str);
		int		_number_check(std::string number) const;

	public:
		bool 		is_empty;
		std::string first;
		std::string last;
		std::string nick;
		std::string number;
		std::string secret;
	
		Contact();
		~Contact();

		int		add();
		void	clear_contact();
		void	display_contact() const;
};

#endif