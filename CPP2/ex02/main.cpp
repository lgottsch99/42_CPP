/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Watanudon <Watanudon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:48:14 by lgottsch          #+#    #+#             */
/*   Updated: 2025/06/08 15:58:31 by Watanudon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>


int main( void ) 
{
	Fixed b(-8.4f);
	Fixed c(2);
	Fixed d(2);

	std::cout << "b is: " << b << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "d is: " << d << std::endl;
	std::cout << "b + c is: " << b + c << std::endl;
	std::cout << "b - c is: " << b - c << std::endl;
	
	std::cout << "is b > c ?";
	if (b > c)
		std::cout << " -yes\n";
	else 
		std::cout << " -no\n";
	
	std::cout << "is b < c ?";
	if (b < c)
		std::cout << " -yes\n";
	else 
		std::cout << " -no\n";

	std::cout << "is b >= c ?";
	if (b >= c)
		std::cout << " -yes\n";
	else 
		std::cout << " -no\n";

	std::cout << "is c <= d ?";
	if (c <= d)
		std::cout << " -yes\n";
	else 
		std::cout << " -no\n";
	
	std::cout << "is c == d ?";
	if (c == d)
		std::cout << " -yes\n";
	else 
		std::cout << " -no\n";

	std::cout << "is c != d ?";
	if (c != d)
		std::cout << " -yes\n";
	else 
		std::cout << " -no\n";
		
	std::cout << "c * d is: " << c * d << std::endl;
	std::cout << "c * b is: " << c * b << std::endl;
	std::cout << "c / d is: " << c / d << std::endl;
	std::cout << "c / b is: " << c / b << std::endl;

	std::cout << "++c is: " << ++c << std::endl;
	std::cout << "c++ is: " << c++ << std::endl;
	std::cout << "c-- is: " << c-- << std::endl;
	std::cout << "--c is: " << --c << std::endl;

	//dif pre and post:
	Fixed e(c++);
	std::cout << "e is: " << e << std::endl;
	std::cout << "c is: " << c << std::endl;
	Fixed f(++c);
	std::cout << "f is: " << e << std::endl;
	std::cout << "c is: " << c << std::endl;
	
	//min max
	std::cout << "min (b, c) is: " << Fixed::min(b, c) << std::endl;
	std::cout << "max (b, c) is: " << Fixed::max(b, c) << std::endl;

	
	std::cout << "\n-----------------------------------\n\n" << std::endl;

	Fixed q;
	Fixed const x( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << q << std::endl;
	std::cout << ++q << std::endl;
	std::cout << q << std::endl;
	std::cout << q++ << std::endl;
	std::cout << q << std::endl;
	
	std::cout << x << std::endl;
	
	std::cout << Fixed::max( q, x ) << std::endl;

	return 0;
}