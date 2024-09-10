/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:51:40 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/28 10:14:38 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const int a)
{
	setRawBits(a << this->bits);
}

Fixed::Fixed(const float a)
{
	this->setRawBits((int)roundf(a * (1 << this->bits)));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &a)
{
	*this = a;
}

Fixed &Fixed::operator=(const Fixed &a)
{
	if (this != &a)
		this->value = a.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream & o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

int Fixed::getRawBits(void) const{return (this->value);}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const{return ((float)this->getRawBits() / (1 << this->bits));}

int Fixed::toInt(void) const{return (this->getRawBits() >> this->bits);}

bool    Fixed::operator>(const Fixed &a) const{return (this->getRawBits() > a.getRawBits());}

bool    Fixed::operator<(const Fixed &a) const{return (this->getRawBits() < a.getRawBits());}

bool    Fixed::operator>=(const Fixed &a) const{return (this->getRawBits() >= a.getRawBits());}

bool   Fixed::operator<=(const Fixed &a) const{return (this->getRawBits() <= a.getRawBits());}

bool  Fixed::operator==(const Fixed &a) const{return (this->getRawBits() == a.getRawBits());}

bool    Fixed::operator!=(const Fixed &a) const{return (this->getRawBits() != a.getRawBits());}

Fixed   Fixed::operator+(const Fixed &a) const{return (Fixed(this->toFloat() + a.toFloat()));}

Fixed   Fixed::operator-(const Fixed &a) const{return (Fixed(this->toFloat() - a.toFloat()));}

Fixed   Fixed::operator*(const Fixed &a) const{return (Fixed(this->toFloat() * a.toFloat()));}

Fixed   Fixed::operator/(const Fixed &a) const{return (Fixed(this->toFloat() / a.toFloat()));}

Fixed	&Fixed::operator++(void)
{
    ++this->value;
    return (*this);
}

Fixed	Fixed::operator++(int)
{
    Fixed tmp(*this);
    tmp.value = this->value++;
    return (tmp);
}

Fixed	&Fixed::operator--(void)
{
    --this->value;
    return (*this);
}

Fixed	Fixed::operator--(int)
{
    Fixed tmp(*this);
    tmp.value = this->value--;
    return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}