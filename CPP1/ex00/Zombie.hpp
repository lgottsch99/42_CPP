/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Watanudon <Watanudon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:04:13 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/27 22:02:22 by Watanudon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

class Zombie
{
	private:
		std::string	_name;
		
	public:

		Zombie( std::string	name );
		~Zombie();

		void announce( void );
};


#endif
