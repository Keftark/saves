/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:50:48 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/27 10:53:06 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string zName;

	std::cout << "\033[2;34mCreate a new zombie: \033[0;37m" << std::endl<< "\033[2;36m>\033[0;37m ";
	std::cin >> zName;
	Zombie z1(zName);
	z1.announce();
	std::cout << "\033[2;34mName a random zombie: \033[0;37m" << std::endl<< "\033[2;36m>\033[0;37m ";
	std::cin >> zName;
	randomChump(zName);	
	std::cout << "\033[2;34mDo it again: \033[0;37m" << std::endl << "\033[2;36m>\033[0;37m ";
	std::cin >> zName;
	Zombie *z2 = newZombie(zName);
	z2->announce();
	delete (z2);
}