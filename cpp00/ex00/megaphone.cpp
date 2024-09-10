/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:07:55 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/22 14:31:35 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for(int i = 1; i < argc; i++)
		{
			for(int o = 0; argv[i][o]; o++)
			{
				std::cout << (char)toupper(argv[i][o]);
			}
			if (i < argc - 1)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
}
