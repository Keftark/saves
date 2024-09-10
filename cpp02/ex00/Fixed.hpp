/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:51:36 by cpothin           #+#    #+#             */
/*   Updated: 2024/03/29 09:28:35 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include "Colors.hpp"

class Fixed
{
	private:
		int value;
		static const int bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &a);
		Fixed &operator=(const Fixed &a);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif