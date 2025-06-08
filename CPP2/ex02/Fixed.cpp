/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Watanudon <Watanudon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:50:41 by lgottsch          #+#    #+#             */
/*   Updated: 2025/06/08 15:56:04 by Watanudon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*
subject does not talk about negative numbers, but supported naturally

Bitshifting, convert int to fixed point means moving the int bits before "point"
"point" is left of ffractional bit positions 
xxxxxxxxxxxxxx.xxxxxxxx

Range of int in Fixed class:
	sizeof(int) * 8 bits = 32 bits on most modern systems
	32 - fractional bits (24 in case fractional is 8)
	range: 
	min: -2 ^ (24 - 1) // -1 for sign
	max: 2 ^ (24 - 1)


*/

//constructor for static member (static members + SHARED btw all o bjects of same class)
const int Fixed::_FractionalBit = 8;


Fixed::Fixed(void): _FixedPointValue(0)
{
	// std::cout << "Default constructor (void) called\n";
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called\n";
	_FixedPointValue = num << _FractionalBit;
	
}

Fixed::Fixed(const float num)
{
	//convert float to fixed point value
	//1. mult by scale factor(1 << _FractionalBit)
	//2. convert to fp

	// std::cout << "Float constructor called\n";
	_FixedPointValue = static_cast<int>(roundf(num * (1 << _FractionalBit)));
}


Fixed::~Fixed(void)
{
	// std::cout << "Destructor called\n";
}

//copy constructor
Fixed::Fixed(const Fixed& ex)
{
	// std::cout << "Copy constructor called\n";
	this->_FixedPointValue = ex.getRawBits();
}

//copy assignment operator
Fixed &Fixed::operator=(const Fixed &e)
{	
	// std::cout << "Copy assignment operator called\n";
	if (this != &e) //protection against self assignment
	{
		this->_FixedPointValue = e.getRawBits();
	}
	return (*this); //->it lets us chain assignments like a = b = c;
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
	return ((static_cast<float>(_FixedPointValue)) / (1 << _FractionalBit));
}

//converts the fixed-point value to an integer value.
/* static cast: c++ way of typecasting, safer than c-style cast (int), has compile time check if cast is possible

c_style cast: a mix of different casting methods that are tried after each other, not type safe, not recommended in c++

(int) was always truncating towards 0 (-8.3 -> -9)
roundf alone always away from 0 (-8.6 -> -8)
*/
int		Fixed::toInt( void ) const
{
	return static_cast<int>(roundf(toFloat()));
}

//cout is object of class std::ostream, cin of class std::istream
// https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed)//OK
{
	ostream << fixed.toFloat();
	return (ostream);
}

// > < >= <= == !=
bool Fixed::operator>(const Fixed& other) const
{
	if (this->getRawBits() > other.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator<(const Fixed& other) const
{
	if (this->getRawBits() < other.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator>=(const Fixed& other) const
{
	if (this->getRawBits() >= other.getRawBits())
		return true;
	else
		return false;
	
}

bool Fixed::operator<=(const Fixed& other) const
{
	if (this->getRawBits() <= other.getRawBits())
		return true;
	else
		return false;

}

bool Fixed::operator==(const Fixed& other) const
{
	if (this->getRawBits() == other.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator!=(const Fixed& other) const
{
	if (this->getRawBits() != other.getRawBits())
		return true;
	else
		return false;
}

//+ - * /
Fixed Fixed::operator+(const Fixed& other) const //one param is this* other is other
{
	Fixed result;

	result.setRawBits(this->_FixedPointValue + other.getRawBits());
	return (result);
}


Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;

	result.setRawBits(this->_FixedPointValue - other.getRawBits());
	return (result);
}

/*
Multiplication:
product = rawA * rawB;
(A × 256) × (B × 256) = (A × B) × 65536 ; (if fracbits = 8)

-> need to scale back down to only 1 x 256:
(A × B) × 65536 ÷ 256  =  (A × B) × 256

-> thats why: product >> _FractionalBit
*/
Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	int64_t product; //need bigger type to store result and avoid overflow

	product = static_cast <int64_t>((this->_FixedPointValue) * other.getRawBits());
	result.setRawBits(static_cast <int> (product >> _FractionalBit)); //scale back down to og type (int 32)
	return (result);
}

/*
Division:
result = rawA / rawB
(a × 256) / (b × 256) = a / b ; scaling factors cancel out
-> BUT: now result is pure float without scaling!
-> need to put it back into fp scale: scale one quotient before division! else truncation
*/
Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	int64_t quotient; //need bigger type to store result and avoid overflow

	quotient = static_cast <int64_t>(((this->_FixedPointValue) << _FractionalBit) / other.getRawBits()); // scale one before division! else losing precision due to truncation
	result.setRawBits(static_cast <int> (quotient)); //scale back UP to og type (int 32)
	return (result);
}

/*
https://en.cppreference.com/w/cpp/language/operator_incdec.html
e is epsilon: smallest unit possible to increment
ε = 1 / (1 << _FractionalBit)
  = 1 / 256

*/
// ++o --o o++ o-- 
//pre: -> modifies object, returns reference
Fixed& Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

//post: -> saves old copy, modifies object, returns copy of old value
//int is dummy param to differ btw pre and post
Fixed Fixed::operator++(int)
{
	Fixed tmp;

	tmp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp;
	
	tmp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}


//members
Fixed& Fixed::min(Fixed& one, Fixed& two) //allows mutation of returned result
{
	if (one < two)
		return one;
	else
		return two;
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two)//does not allow mutation of returned result, read only
{
	Fixed tmp_one(one);
	Fixed tmp_two(two);
	if (tmp_one < tmp_two)
		return one;
	else
		return two;
}

Fixed& Fixed::max(Fixed& one, Fixed& two) //allows mutation of returned result
{
	if (one > two)
		return one;
	else
		return two;
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two)//does not allow mutation of returned result, read only
{
	Fixed tmp_one(one);
	Fixed tmp_two(two);
	if (tmp_one > tmp_two)
		return one;
	else
		return two;
}
