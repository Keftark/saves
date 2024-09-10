/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:56:00 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/12 16:29:42 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->brain = new Brain("Cat now has a brain!");
}

Cat::~Cat()
{
	delete (this->brain);
}

void Cat::makeSound() const
{
	std::cout << DARKTEAL << this->type << LIME << " meows." << RESET << std::endl;
}