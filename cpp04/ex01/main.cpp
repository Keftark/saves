/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:26:50 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/28 11:55:06 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animals[6] = {new Dog(), new Dog(), new Dog(), new Cat(), new Cat(), new Cat()};
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl;
	delete j;//should not create a leak
	delete i;
	std::cout << std::endl;
	// delete animals[0];
	// delete animals[1];
	// delete animals[2];
	// delete animals[3];
	// delete animals[4];
	// delete animals[5];
	for (int o = 0; o < 6; o++)
		delete animals[o];

	return 0;
}
