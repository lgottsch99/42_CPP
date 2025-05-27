/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:04:13 by lgottsch          #+#    #+#             */
/*   Updated: 2025/05/27 16:21:33 by lgottsch         ###   ########.fr       */
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

		Zombie();
		~Zombie();

		void announce( void );
};


#endif
