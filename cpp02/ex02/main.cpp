/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:26:50 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/28 10:19:12 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << RGB(0, 255, 255) << a << RESET << std::endl;
	std::cout << RGB(0, 255, 215) << ++a << RESET << std::endl;
	std::cout << RGB(0, 255, 175) << a << RESET << std::endl;
	std::cout << RGB(0, 255, 135) << a++ << RESET << std::endl;
	std::cout << RGB(0, 255, 85) << a << RESET << std::endl;
	std::cout << RGB(0, 255, 45) << b << RESET << std::endl;
	std::cout << RGB(0, 255, 0) << Fixed::max( a, b ) << RESET << std::endl;
	return 0;
}
