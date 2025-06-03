/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:19 by lgottsch          #+#    #+#             */
/*   Updated: 2025/06/03 16:55:02 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int					_value;
		static const int	_bit; //=number of fractional bits

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

#endif