/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:00:28 by cpothin           #+#    #+#             */
/*   Updated: 2024/02/26 16:54:29 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	// asked by the subject
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	// end

	unsigned int nbElements = 10;
	std::cout << std::endl << GREEN << "Creating a fixed size list of " << nbElements << " elements..." << RESET << std::endl << std::endl;

	Span sp2 = Span(nbElements);
	sp2.addNumbers(nbElements);
	std::cout << TEAL << "Shortest span: " << GOLD << sp2.shortestSpan() << RESET << std::endl;
	std::cout << TEAL << "Longest span: " << GOLD << sp2.longestSpan() << RESET << std::endl;

	// Used to show the list. Uncomment it to see what it does.
	// Obviously, the list can be very big and we can't see all the generated numbers.

	std::cout << std::endl << GREEN << "Finding numbers below a valuem for testing if the random works correctly..." << RESET << std::endl << std::endl;
	std::list<int> myList = sp2.getList();
	int i = 0;
	for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
	{
		if (*it < (int)nbElements)
		{
			i++;
			std::cout << *it << std::endl;
		}
	}
	if (i == 0)
		std::cout << RED << "No value was found." << RESET << std::endl;
	return 0;
}
