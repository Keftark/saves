/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:00:28 by cpothin           #+#    #+#             */
/*   Updated: 2024/02/16 10:16:17 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    std::cout << TEAL <<
        "First step: finding a value in a vector."
        << RESET << std::endl << std::endl;
    
	std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    easyfind(vec, 5);

    std::cout << std::endl << TEAL <<
        "Now we will try to find a value in a list, but it will fail, lol."
        << RESET << std::endl << std::endl;

    std::list<int> lst;
    for (int i = 1; i < 6; i++)
        lst.push_back(i);
    easyfind(lst, -12);

    std::cout << std::endl << TEAL <<
        "This is another vector but this time we fail to find the value."
        << RESET << std::endl << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vect(arr, arr + sizeof(arr) / sizeof(int));
    easyfind(vect, 8);

    std::cout << std::endl << TEAL <<
        "We make a second list and we find a value in it."
        << RESET << std::endl << std::endl;
    std::list<int> myList(vect.begin(), vect.end());
    easyfind(vect, 3);

    std::cout << std::endl << "(Not asked, but I wanted to do it)" << std::endl << TEAL <<
        "Finally, we make a map and try to find a value in its keys."
        << RESET<< std::endl << std::endl;
    std::map<int, std::string> myMap;
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";
    myMap[4] = "Four";
    myMap[5] = "Five";
    easyfind(myMap, 1);
}
