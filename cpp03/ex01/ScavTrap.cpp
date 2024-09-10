/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:39:21 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/28 16:19:57 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamages = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << ORANGE << this->Name << RESET << " is destroyed..." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << ORANGE << this->Name << RESET << " is now in " << RGB(0, 0, 0, background) << RGB(0, 0, 0, foreground) << "Gate Keeper" << RESET << " mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->EnergyPoints <= 0 || this->HitPoints <= 0)
		return ;
	this->EnergyPoints--;
	std::cout << TEAL << this->Name << RESET << " attacks differently, causing " << ROSERED << target << RESET << " to lose " << GOLD << this->AttackDamages << RESET << " hit points." << std::endl;
}