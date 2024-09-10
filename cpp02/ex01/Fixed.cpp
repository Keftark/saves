/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:51:40 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/28 10:29:55 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << ToColor("Default constructor called", Colors::Green) << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int a)
{
	std::cout << ToColor("Int constructor called", Colors::DeepPink) << std::endl;
	setRawBits(a << this->bits);
}

Fixed::Fixed(const float a)
{
	std::cout << ToColor("Float constructor called", Colors::Blue) << std::endl;
	this->setRawBits((int)roundf(a * (1 << this->bits)));
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

std::ostream &operator<<(std::ostream & o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (1 << this->bits));
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->bits);
}
