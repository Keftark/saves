/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:26:50 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/18 18:45:28 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
    ICharacter *me = new Character("Bryan");
	IMateriaSource *source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());
    AMateria *tmp;
    tmp = source->createMateria("Ice");
    me->equip(tmp);
    tmp = source->createMateria("Cure");
    me->equip(tmp);
    ICharacter *miguel = new Character("Miguel");

    me->use(0, *miguel);
    me->unequip(0);
    tmp = source->createMateria("Cure");
    me->equip(tmp);
    tmp = source->createMateria("Cure");
    me->equip(tmp);
    tmp = source->createMateria("Cure");
    me->equip(tmp);
    me->use(0, *miguel);
    me->unequip(0);
    me->use(0, *miguel);
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);
    delete source;
    delete miguel;
    delete me;

    return 0;
}
