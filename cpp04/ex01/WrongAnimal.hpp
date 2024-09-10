/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:12:30 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/28 11:49:03 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include "Colors.hpp"

class WrongAnimal
{
	protected:
		std::string type;
	private:

	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &a);
    	WrongAnimal &operator=(const WrongAnimal &a);
		virtual void makeSound() const;
		std::string getType() const;
};

#endif