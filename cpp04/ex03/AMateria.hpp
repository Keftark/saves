/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:51:35 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/18 18:43:12 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "Colors.hpp"
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		virtual ~AMateria();
		AMateria(const std::string &type);
    	AMateria (const AMateria &a);
    	AMateria &operator=(const AMateria &a);
		std::string const &getType() const; //Returns the materia type
		std::string getType0();
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif