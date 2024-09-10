/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:37:56 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/16 09:22:49 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (materias[i])
            delete (materias[i]);
}

MateriaSource::MateriaSource(MateriaSource const &a)
{
    *this = a;
}

MateriaSource& MateriaSource::operator=(MateriaSource const &a)
{
    if (this != &a)
    {
        for (int i = 0; i < 4; i++)
            materias[i] = a.materias[i];
    }
    return (*this);
}

AMateria* MateriaSource::getMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
        if (materias[i] && materias[i]->getType() == type)
            return materias[i];
    return (NULL);
}

void    MateriaSource::learnMateria(AMateria *a)
{
    for (int i = 0; i < 4; i++)
        if (materias[i] == NULL)
        {
            materias[i] = a;
            return ;
        }
}

AMateria*   MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return (NULL);
}