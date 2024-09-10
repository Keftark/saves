/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:09:54 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/27 15:26:59 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponName)
{
	this->setType(weaponName);
}

Weapon::~Weapon()
{
	
}

std::string &Weapon::getType()
{
	return (this->weaponType);
}

void Weapon::setType(std::string newType)
{
	this->weaponType = newType;
}
