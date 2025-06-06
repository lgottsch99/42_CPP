/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:19 by lgottsch          #+#    #+#             */
/*   Updated: 2025/06/06 17:22:27 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_FixedPointValue;
		static const int	_FractionalBit;

	public:
		Fixed(void); //default constructor
		Fixed(const Fixed& ex); //copy constructor
		Fixed &operator = (const Fixed& e);//copy assignment operator
		~Fixed(); //destructor

		Fixed(const int num);
		Fixed(const float num);

		float	toFloat( void ) const;
		int 	toInt( void ) const;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );


};

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed);

#endif