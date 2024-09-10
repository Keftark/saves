/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:50:28 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/29 17:54:26 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::debug(void)
{
	std::cout << "This is a debug log." << std::endl;
}

void Harl::info(void)
{
	std::cout << "This is an info log." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "This is a warning log." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is an error log." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*funcPtrs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"Debug", "Info", "Warning", "Error"};
	int i = 0;

	while (levels[i].compare(level))
		i++;
	while (i >= 0)
	{
		(this->*funcPtrs[i])();
		i--;
	}
}
