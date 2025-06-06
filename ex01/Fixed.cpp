/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:50:41 by lgottsch          #+#    #+#             */
/*   Updated: 2025/06/06 17:30:37 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/*
subject does not talk about negative numbers
*/


//constructor for static member (static members + SHARED btw all o bjects of same class)
const int Fixed::_FractionalBit = 8;


Fixed::Fixed(void): _FixedPointValue(0)
{
	std::cout << "Default constructor (void) called\n";
}

/*
Bitshifting, convert int to fixed point means moving the int bits before "point"
"point" is left of ffractional bit positions 
*/
Fixed::Fixed(const int num) //OK  
{
	//TODO convert to corresponding fixed point value
	
	std::cout << "Int constructor called\n";
	_FixedPointValue = num << _FractionalBit; //scaling up , moving int parts to left of "point"
	
}

Fixed::Fixed(const float num) //TODO  not same as subject
{
	//TODO convert float to fixed point value
	//1. mult by scale factor(1 << _FractionalBit)
	//2. convert to fp

	std::cout << "Float constructor called\n";
	_FixedPointValue = (int) (num * (1 << _FractionalBit));
}


Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

//copy constructor
Fixed::Fixed(const Fixed& ex)
{
	std::cout << "Copy constructor called\n";
	this->_FixedPointValue = ex.getRawBits();
}

//copy assignment operator
//not a construction ft! so no list
Fixed &Fixed::operator=(const Fixed &e)
{
	std::cout << "Copy assignment operator called\n";
	this->_FixedPointValue = e.getRawBits();
	return (*this);
}

//returns the raw value of the fixed-point value
int	Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called\n";
	return (_FixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	_FixedPointValue = raw;
	return ;
}

// https://medium.com/incredible-coder/converting-fixed-point-to-floating-point-format-and-vice-versa-6cbc0e32544e 
float	Fixed::toFloat( void ) const
{
	//TODO converts the fixed-point value to a floating-point value.
	//1. convert fixed point value to float
	//2. scale down to real number (remove bits after "point")? =divide down by scale factor

	//SCALE_FACTOR (1 << frac bits) ???????????
	return (((float)_FixedPointValue) / (1 << _FractionalBit));
}

//converts the fixed-point value to an integer value.
int		Fixed::toInt( void ) const
{
	return (_FixedPointValue >> _FractionalBit); //OK
}

//cout is object of class std::ostream, cin of class std::istream
// https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed)//OK
{
	ostream << fixed.toFloat();
	return (ostream);
}