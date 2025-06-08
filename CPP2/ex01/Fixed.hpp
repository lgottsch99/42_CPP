/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Watanudon <Watanudon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:19 by lgottsch          #+#    #+#             */
/*   Updated: 2025/06/08 11:25:19 by Watanudon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// https://youtu.be/i1phJl-0v54?feature=shared 


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