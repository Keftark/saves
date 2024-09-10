/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:27:25 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/18 18:26:35 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
{
	// std::cout << LIGHTTEAL << this->type << RESET << Rainbow(" is created.") << std::endl;
}

Ice::~Ice()
{
	// std::cout << LIGHTTEAL << this->type << RESET << ROSERED << " is destroyed." << RESET << std::endl;
}

Ice::Ice(const Ice &a)
{
	*this = a;
	std::cout << Rainbow("A clone named ") << TEAL << this->type << RESET << Rainbow(" is created.") << std::endl;
}

Ice &Ice::operator=(const Ice &a)
{
    this->type = a.type;
    return (*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << ToColor(" * shoots an ice bolt at ", Colors::MistyRose) << LIGHTTEAL << target.getName() << RESET << ToColor(" *", Colors::MistyRose) << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}
