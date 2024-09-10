/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:07:51 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/12 16:28:00 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << Rainbow("Brain is created.") << std::endl;
}

Brain::~Brain()
{
}
Brain::Brain(std::string msg)
{
	std::cout << ToColor(msg, (Color){255, 228, 225}, Colors::Red) << RESET << std::endl;
	// std::cout << ToColor(msg, Colors::MistyRose, Colors::Red) << RESET << std::endl;
}

Brain::Brain(const Brain &a)
{
	*this = a;
	std::cout << Rainbow("A clone of the Brain is created.") << std::endl;
}

Brain &Brain::operator=(const Brain &a)
{
    std::cout << "Brain assignment operator called." << std::endl;
	if (this != &a)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = a.ideas[i];
    return (*this);
}