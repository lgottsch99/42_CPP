/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:32:12 by Watanudon         #+#    #+#             */
/*   Updated: 2025/05/29 14:45:41 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

class Zombie
{		
	private:
		std::string	_name;
	
	public:
		
		Zombie( void );
		~Zombie();

		void	announce( void );
		void	setname( std::string name );
};


#endif
