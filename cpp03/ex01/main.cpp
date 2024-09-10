/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:26:50 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/28 16:20:19 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("Georges");
	clap.attack("Michel");
	clap.takeDamage(5);
	clap.beRepaired(5);
	ScavTrap scav("Jean");
	scav.attack("Michel2");
	scav.guardGate();
}
