/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:04:53 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/28 11:27:47 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "Colors.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->EnergyPoints = 10;
	this->AttackDamages = 10;
	this->HitPoints = 10;
	std::cout << TEAL << name << RESET << Rainbow(" emerges from the ashes...") << std::endl;
	this->Name = name;
}

ClapTrap::~ClapTrap()
{
	std::cout << TEAL << this->Name << RESET << Rainbow(" returns to earth.") << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &a)
{
    std::cout << "A ClapTrap clone is created." << std::endl;
    *this = a;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &a)
{
    this->Name = a.Name;
    this->HitPoints = a.HitPoints;
    this->EnergyPoints = a.EnergyPoints;
    this->AttackDamages = a.AttackDamages;
    return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->EnergyPoints <= 0 || this->HitPoints <= 0)
		return ;
	this->EnergyPoints--;
	std::cout << TEAL << this->Name << RESET << " attacks, causing " << ROSERED << target << RESET << " to lose " << GOLD << this->AttackDamages << RESET << " hit points." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->HitPoints -= amount;
	if (this->HitPoints <= 0)
		std::cout << TEAL << this->Name << RESET << " takes " << GOLD << amount << RESET << " damages and is destroyed..." << std::endl;
	else
		std::cout << TEAL << this->Name << RESET << " takes " << GOLD << amount << RESET << " damages!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints <= 0 || this->HitPoints <= 0)
		return ;
	this->EnergyPoints--;
	this->HitPoints += amount;
	std::cout << TEAL << this->Name << RESET << " repairs itself, it gets " << GOLD << amount << RESET << " hit points back." << std::endl;
}
