/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:04:56 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/28 11:48:14 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Colors.hpp"

class Animal
{
	protected:
		std::string type;
	private:

	public:
		Animal();
		virtual ~Animal();
		Animal(std::string type);
		Animal(const Animal &a);
    	Animal &operator=(const Animal &a);
		virtual void makeSound() const;
		std::string getType() const;
};

#endif