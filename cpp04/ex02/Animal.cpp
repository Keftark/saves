/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:07:19 by cpothin           #+#    #+#             */
/*   Updated: 2024/04/05 16:20:34 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << LIGHTTEAL << this->type << RESET << Rainbow(" is created.") << std::endl;
}

Animal::~Animal()
{
	std::cout << LIGHTTEAL << this->type << RESET << ROSERED << " died." << RESET << std::endl;
}
Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << LIGHTTEAL << type << RESET << ToColor(" is created.", 2, Colors::Green, Colors::Red) << std::endl;
}

Animal::Animal(const Animal &a)
{
	*this = a;
	std::cout << "A clone named " << TEAL << this->type << RESET << Rainbow(" is created.") << std::endl;
}

Animal &Animal::operator=(const Animal &a)
{
    this->type = a.type;
    return (*this);
}

void Animal::makeSound() const
{
	std::cout << LIGHTTEAL << this->type << RESET << ORANGE << " makes a sound." << RESET << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

