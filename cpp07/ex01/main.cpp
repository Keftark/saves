/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:00:28 by cpothin           #+#    #+#             */
/*   Updated: 2024/02/20 14:34:50 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "iter.hpp"

template <typename T>
void	showInfo(const T &a)
{
	std::cout << a << std::endl;
}

void	addOne(int const &a)
{
	std::cout << a;
}

int main(void)
{
	std::string strs[5] =
	{
		Rainbow("Salut comment ca va ?"),
		Rainbow("Ca va et toi ?"),
		Rainbow("Ca va et toi ?"),
		Rainbow("Ca va et toi ?"),
		RGB2(Colors::Red, Colors::Black) + 
		"Et bla bla bla, une conversation qui n'en est pas vraiment une..." + RESET
	};
	iter(strs, 5, showInfo);
	int nbrs[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::cout << RGB(Colors::Gold);
	iter(nbrs, 9, addOne);
	std::cout << RESET << std::endl;
}
