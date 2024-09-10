/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:16:39 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/06 14:40:23 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Wrong Animal";
	std::cout << BROWN << this->type << RESET << Rainbow(" is created.") << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BROWN << this->type << RESET << ROSERED << " died." << RESET << std::endl;
}
WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << BROWN << type << RESET << ToColor(" is created.", Colors::Red, Colors::Green) << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
	*this = a;
	std::cout << "A clone named " << BROWN << this->type << RESET << Rainbow(" is created.") << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a)
{
    std::cout << "Wrong Animal assignment operator called" << std::endl;
    this->type = a.type;
    return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << ToColor("Wrong Animal makes a weird sound.", Colors::Brown, Colors::Orange) << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}