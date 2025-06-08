/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Watanudon <Watanudon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:19 by lgottsch          #+#    #+#             */
/*   Updated: 2025/06/08 15:53:31 by Watanudon        ###   ########.fr       */
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
		Fixed(const int num);
		Fixed(const float num);
		
		Fixed(const Fixed& ex); //copy constructor
		Fixed &operator = (const Fixed& e);//copy assignment operator
		~Fixed(); //destructor

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int 	toInt( void ) const;

		//operators:
		// > < >= <= == !=
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		//+ - * /
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// ++o --o o++ o-- 
		//pre
		Fixed& operator++();
		Fixed& operator--();
		//post
		Fixed operator++(int);
		Fixed operator--(int);

		//members:
		static 			Fixed& min(Fixed& one, Fixed& two);
		static const 	Fixed& min(const Fixed& one, const Fixed& two);
		static 			Fixed& max(Fixed& one, Fixed& two);
		static const 	Fixed& max(const Fixed& one, const Fixed& two);



};

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed);

#endif