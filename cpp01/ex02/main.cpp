/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:51:01 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/28 09:29:05 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str =  "This is a string";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << std::endl;
	std::cout << "Memory address of str: \033[0;36m " << &str << "\033[0;37m" << std::endl;
	std::cout << "Memory address of stringPTR: \033[0;36m " << stringPTR << "\033[0;37m" << std::endl;
	std::cout << "Memory address of stringREF: \033[0;36m " << &stringREF << "\033[0;37m" << std::endl << std::endl;

	std::cout << "Value of str: \033[0;36m " << str << "\033[0;37m" << std::endl;
	std::cout << "Value of stringPTR: \033[0;36m " << *stringPTR << "\033[0;37m" << std::endl;
	std::cout << "Value of stringREF: \033[0;36m " << stringREF << "\033[0;37m" << std::endl;
	std::cout << std::endl;
}
