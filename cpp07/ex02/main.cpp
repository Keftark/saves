/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:00:28 by cpothin           #+#    #+#             */
/*   Updated: 2024/02/03 15:25:47 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Array.hpp"

int main(void)
{
    Array<float> test(2);
    Array<int> test2(1);
    Array<int> intArray(5);

	intArray[0] = 1;
	intArray[1] = 10;
	intArray[2] = 12;
	intArray[3] = 20;
	intArray[4] = 30;

	std::cout << RGB(Colors::Blue) << "Testing intArray: " << RESET << std::endl << std::endl
		<< RGB(Colors::NightBlue) << "Size:" << std::endl << RGB(Colors::RoyalBlue) << intArray.Size() << RESET << std::endl;
	std::cout << intArray << std::endl << std::endl;
	test2[0] = 42;
	intArray = test2;
	std::cout << RGB(Colors::Cyan) << "----------------------------------------" << RESET << std::endl << std::endl;
	std::cout << RGB(Colors::Blue) << "Testing intArray = test2:" << RESET << std::endl << std::endl
		<< RGB(Colors::NightBlue) << "Size:" << std::endl << RGB(Colors::RoyalBlue) << intArray.Size() << RESET << std::endl;
	std::cout << intArray << std::endl << std::endl;
	std::cout << RGB(Colors::Cyan) << "----------------------------------------" << RESET << std::endl << std::endl;
	std::cout << RGB(Colors::Blue) << "Error testing:" << std::endl << std::endl;
	try
	{
		test2[1] = 1;
	}
	catch(const std::exception& e)
	{
		std::cout << RGB2(Colors::Red, Colors::Black) << e.what() << RESET << std::endl << std::endl;
	}
	
}
