/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:51:18 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/18 18:43:03 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "Empty materia";
}

AMateria::AMateria(std::string const &type)
{
    this->type = type;
	std::cout << LIGHTTEAL << this->type << RESET << Rainbow(" is created.") << std::endl;
}

AMateria::~AMateria()
{
	std::cout << LIGHTTEAL << this->type << RESET << ROSERED << " is destroyed." << RESET << std::endl;
}

AMateria::AMateria(const AMateria &a)
{
	*this = a;
	std::cout << Rainbow("A clone named ") << TEAL << this->type << RESET << Rainbow(" is created.") << std::endl;
}

AMateria &AMateria::operator=(const AMateria &a)
{
    this->type = a.type;
    return (*this);
}

std::string const &AMateria::getType() const
{
    return (this->type);
}

std::string AMateria::getType0()
{
	return (TEAL + this->getType() + RESET);
}

AMateria* AMateria::clone() const
{
	return ((AMateria*)this);
}

void AMateria::use(ICharacter &target)
{
	std::cout << target.getName() << " uses a materia." << std::endl;
}