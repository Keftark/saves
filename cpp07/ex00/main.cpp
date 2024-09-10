/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:00:28 by cpothin           #+#    #+#             */
/*   Updated: 2024/02/20 14:32:55 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "whatever.hpp"

int main( void )
{
	int a = 2;
	int b = 3;
	std::cout << TEAL << "Before swap:" << std::endl <<
		"a: " << GOLD << a << TEAL << std::endl <<
		"b: " << GOLD << b << RESET << std::endl << std::endl;
	::swap(a, b);
	std::cout << TEAL << "After swap:" << std::endl <<
		"a: " << GOLD << a << TEAL << std::endl <<
		"b: " << GOLD << b << RESET << std::endl << std::endl;
	std::cout << "a = " << RGB(Colors::Green) << a << RESET << ", b = " << RGB(Colors::Green) << b << RESET << std::endl;
	std::cout << "min(a, b) = " << RGB(Colors::Green) << ::min(a, b) << RESET << std::endl;
	std::cout << "max(a, b) = " << RGB(Colors::Green) << ::max(a, b) << RESET << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << std::endl << TEAL << "Before swap:" << std::endl <<
		"c: " << GOLD << c << TEAL << std::endl <<
		"d: " << GOLD << d << RESET << std::endl << std::endl;
	::swap(c, d);
	std::cout << TEAL << "After swap:" << std::endl <<
		"c: " << GOLD << c << TEAL << std::endl <<
		"d: " << GOLD << d << RESET << std::endl << std::endl;
	std::cout << "c = " << RGB(Colors::Green) << c << RESET << ", d = " << RGB(Colors::Green) << d << RESET << std::endl;
	std::cout << "min(c, d) = " << RGB(Colors::Green) << ::min(c, d) << RESET << std::endl;
	std::cout << "max(c, d) = " << RGB(Colors::Green) << ::max(c, d) << RESET << std::endl;
	return 0;
}
