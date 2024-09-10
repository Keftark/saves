/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:56:04 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/12 16:27:51 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->brain = new Brain("Dog now has a brain!");
}

Dog::~Dog()
{
	delete (this->brain);
}

void Dog::makeSound() const
{
	std::cout << DARKTEAL << this->type << BLUE << " barks." << RESET << std::endl;
}
