/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:26:50 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/28 10:08:41 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);
	std::cout << ToColor("a", Colors::LightTeal) << " is " << CYAN << a << RESET << std::endl;
	std::cout << ToColor("b", Colors::LightTeal) << " is " << CYAN << b << RESET << std::endl;
	std::cout << ToColor("c", Colors::LightTeal) << " is " << CYAN << c << RESET << std::endl;
	std::cout << ToColor("d", Colors::LightTeal) << " is " << CYAN << d << RESET << std::endl;
	std::cout << ToColor("a", Colors::LightTeal) << " is " << CYAN << a.toInt() << RESET << " as integer" << std::endl;
	std::cout << ToColor("b", Colors::LightTeal) << " is " << CYAN << b.toInt() << RESET << " as integer" << std::endl;
	std::cout << ToColor("c", Colors::LightTeal) << " is " << CYAN << c.toInt() << RESET << " as integer" << std::endl;
	std::cout << ToColor("d", Colors::LightTeal) << " is " << CYAN << d.toInt() << RESET << " as integer" << std::endl;
	return (0);
}
