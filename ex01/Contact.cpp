/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:53:03 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/20 16:42:48 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

/*
Method: ft that belongs to a class

Constructor: ft that is autom. called when class is created
			-> needs same name as Class!
Member: data inside classes
	Note: By default, all members of a class are private if you don't 
	specify an access specifier!
*/

class Contact
{
	public:				//Access specifier
		void shout();	//Method
		string first;	//Member
		string last;
		string nick;
		string number;
		string secret;
		Contact(string first, string last, string nick, string number, string secret);		//Constructor

};

Contact::Contact(string first, string last, string nick, string number, string secret)
{
	first = "";
	last = "";
	nick = "";
	number = "";
	secret = '';
}

void	Contact::shout()
{
	std::cout << "HELLOOOOOOO" << endl;

}