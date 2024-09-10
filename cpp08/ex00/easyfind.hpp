#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "Colors.hpp"
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <map>

template <typename T>
void easyfind(T &what, int toFind)
{
	if (std::find(what.begin(), what.end(), toFind) != what.end())
		std::cout << LIME << toFind << " is found!" << RESET << std::endl;
	else
		std::cout << ERRCOLOR << toFind << " is not found!" << RESET << std::endl;
}
template <typename K, typename V>
void easyfind(std::map<K, V> &what, int toFind)
{
	typename std::map<K, V>::iterator it = what.find(toFind);
    if (it != what.end())
		std::cout << LIME << toFind << " is found! Its value is " << GOLD << it->second << LIME << "." << RESET << std::endl;
	else
		std::cout << ERRCOLOR << toFind << " is not found!" << RESET << std::endl;
}

#endif