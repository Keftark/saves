/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:07:15 by cpothin           #+#    #+#             */
/*   Updated: 2024/04/05 10:03:48 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include "Colors.hpp"

class Brain
{
	protected:
		std::string ideas[100];
	private:

	public:
		Brain();
		~Brain();
		Brain(std::string msg);
		Brain(const Brain &a);
    	Brain &operator=(const Brain &a);
};

#endif