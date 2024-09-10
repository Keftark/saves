/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:26:45 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/18 18:26:29 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(const Cure &a)
{
	*this = a;
	std::cout << Rainbow("A clone named ") << TEAL << this->type << RESET << Rainbow(" is created.") << std::endl;
}

Cure &Cure::operator=(const Cure &a)
{
    this->type = a.type;
    return (*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << ToColor(" * heals ", Colors::MistyRose) << LIGHTTEAL << target.getName() << RESET << ToColor("'s wounds *", Colors::MistyRose) << std::endl;
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}
