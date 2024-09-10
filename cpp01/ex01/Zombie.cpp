/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:35:38 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/25 12:27:23 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << "Poor " << this->zName << ", he has been \033[1;31mkilled\033[0;37m!" << std::endl;
}

void Zombie::announce(std::string name)
{
	this->zName = name;
	std::cout << this->zName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}