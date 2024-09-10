/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:33:13 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/25 12:27:32 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string zName;
	public:
		Zombie();
		~Zombie();
		void	announce(std::string name);
		Zombie* zombieHorde(int N, std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif