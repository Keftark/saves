/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:56:04 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/06 14:22:50 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
}

Dog::~Dog()
{

}

void Dog::makeSound() const
{
	std::cout << DARKTEAL << this->type << BLUE << " barks." << RESET << std::endl;
}
