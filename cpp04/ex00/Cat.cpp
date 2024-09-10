/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:56:00 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/06 14:59:16 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	
}

Cat::~Cat()
{

}

void Cat::makeSound() const
{
	std::cout << DARKTEAL << this->type << LIME << " meows." << RESET << std::endl;
}