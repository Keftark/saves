/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:35:56 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/05 09:21:00 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamages = 20;
	std::cout << LIME << this->Name << RESET << Rainbow(" is now operational.") << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << LIME << this->Name << RESET << " is destroyed, but \033[33;4mdifferently\033[0m than this stupid " << BROWN << "ScavTrap" << RESET << "..." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << LIME << this->Name << RESET << " high fives its friends." << std::endl;
}