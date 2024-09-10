/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:51:36 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/28 10:13:37 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const int a);
		Fixed(const float a);
		Fixed(const Fixed &a);
		~Fixed();
		Fixed	&operator=(const Fixed &a);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		bool	operator>(const Fixed &a) const;
		bool	operator<(const Fixed &a) const;
		bool	operator>=(const Fixed &a) const;
		bool	operator<=(const Fixed &a) const;
		bool	operator==(const Fixed &a) const;
		bool	operator!=(const Fixed &a) const;
		Fixed   operator+(const Fixed &a) const;
		Fixed   operator-(const Fixed &a) const;
		Fixed   operator*(const Fixed &a) const;
		Fixed   operator/(const Fixed &a) const;
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);
	    static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif