/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:51:40 by cpothin           #+#    #+#             */
/*   Updated: 2024/03/29 09:28:38 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << ToColor("Default constructor called", Colors::Green) << std::endl;
	this->value = 0;
}

Fixed::~Fixed()
{
	std::cout << ToColor("Destructor called", Colors::Red) << std::endl;
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << ToColor("Copy constructor called", Colors::Violet) << std::endl;
	*this = a;
}

Fixed &Fixed::operator=(const Fixed &a)
{
	std::cout << ToColor("Copy assignment operator called", Colors::Yellow) << std::endl;
	if (this != &a)
		this->value = a.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << ToColor("getRawBits member function called", Colors::RoyalBlue) << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}