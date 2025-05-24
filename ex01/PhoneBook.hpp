/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:41:58 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/24 15:53:42 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"


/* const for safety, functions accessing all members in read only mode 
(aka) never setting any new values -> good to use const
*/

class PhoneBook
{
	void	_padded_field(std::string str) const;

	public:
		Contact people[8];
				
		void	show_saved_contacts() const;
};

#endif