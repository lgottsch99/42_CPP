/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Watanudon <Watanudon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:32:12 by Watanudon         #+#    #+#             */
/*   Updated: 2025/05/27 22:59:15 by Watanudon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

class Zombie
{		
	public:
		std::string	_name;
		
		Zombie( void );
		~Zombie();

		void announce( void );
};


#endif
