/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:33:13 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/25 12:00:05 by cpothin          ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
		Zombie* newZombie(std::string name);
		void	randomChump(std::string name);
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif