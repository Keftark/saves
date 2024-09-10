/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:39:02 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/18 18:48:46 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->materias[i])
			delete (this->materias[i]);
	std::cout << this->getName() << ROSERED << " died." << RESET << std::endl;
}
Character::Character(std::string const &name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
        this->materias[i] = NULL;
	std::cout << this->getName() << ToColor(" is born.", 2, Colors::Green, Colors::Red) << std::endl;
}

Character::Character(const Character &a)
{
	*this = a;
	std::cout << Rainbow("A clone named ") << TEAL << this->name << RESET << Rainbow(" is born.") << std::endl;
}

Character &Character::operator=(const Character &a)
{
    this->name = a.name;
	for (int i = 0;i < 4; i++)
		this->materias[i] = a.materias[i];
    return (*this);
}

std::string const &Character::getName() const
{
    static std::string result;

    result = LIGHTTEAL + this->name + RESET;
    return result;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] == NULL)
		{
			this->materias[i] = m;
			std::cout << this->getName() << ToColor(" equips with the ", Colors::MistyRose) << m->getType0() << ToColor(" materia!", Colors::MistyRose) << std::endl;
			return ;
		}
	}
	std::cout << this->getName() << ToColor("'s inventory is full!", Colors::MistyRose) << std::endl;
}

void Character::unequip(int idx)
{
	if (this->materias[idx] == NULL)
		return ;
	std::cout << this->getName() << ToColor(" de-equips the ", Colors::MistyRose) << this->materias[idx]->getType0() << ToColor(" materia!", Colors::MistyRose) << std::endl;
	delete this->materias[idx];
	this->materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (!this->materias[idx])
	{
		std::cout << ToColor("No materia equipped at this place!", Colors::DarkBrown) << std::endl;
		return ;
	}
	std::cout << this->getName();
	this->materias[idx]->use(target);
}
