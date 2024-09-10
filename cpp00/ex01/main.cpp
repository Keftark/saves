/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:02:27 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/27 10:41:51 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

enum Menu
{
	MAIN = 0,
	SHOW = 1
};

void ShowControls(Menu &menu)
{
	if (menu == MAIN)
	{
		std::cout << std::endl << "- \033[0;34mADD\033[0;37m: to add a new contact." << std::endl;
		std::cout << "- \033[0;34mSEARCH\033[0;37m: to see the contacts and select one." << std::endl;
		std::cout << "- \033[0;34mEXIT\033[0;37m: to exit the program." << std::endl << std::endl;
		std::cout << "\033[2;37mPlease enter a command:" << std::endl << std::endl << "\033[2;36m>\033[0;37m ";
	}
	else
		std::cout << "\033[2;37mEnter the index (\033[0;34m1-8\033[2;37m) of the contact you want to see." << std::endl \
		<< "Enter \033[0;34m0\033[2;37m to return to the main menu." << std::endl << std::endl << "\033[2;36m>\033[0;37m ";
}

void ShowWelcome(void)
{
	std::string welcome = "Welcome to the D4rk Cricri's PhoneBook!";

	std::cout << "\033[0;33m*******************************************" << std::endl;
	std::cout << "*                                         *" << std::endl << "* \033[0;35m";
	for (int i = 0; welcome[i]; i++)
		std::cout << (char)toupper(welcome[i]);
	std::cout << "\033[0;33m *" << std::endl;
	std::cout << "*                                         *" << std::endl;
	std::cout << "*******************************************\033[0;37m";
	std::cout << std::endl;
}

void HandleMain(PhoneBook &phoneBook, Menu &menu, std::string input)
{
	std::cout << std::endl;
	if (input.compare("ADD") == 0)
	{
		phoneBook.AddContact();
	}
	else if (input.compare("SEARCH") == 0)
	{
		if (phoneBook.ShowContacts() == 1)
			menu = SHOW;
	}
	else
		std::cout << "\033[1;31mThis command does not exist.\033[0;37m" << std::endl;
}

void HandleShow(PhoneBook &phoneBook, Menu &menu, std::string input)
{
	int index;
	std::istringstream iss(input);

	if (!(iss >> index))
	{
		std::cout << std::endl << "\033[1;31mThis is not a valid number\033[0;37m" << std::endl << std::endl;		
		return ;
	}
	if (index == 0)
		menu = MAIN;
	else if (index < 1 || index > 8)
		std::cout << std::endl << "\033[1;31mThis is not a valid number\033[0;37m" << std::endl << std::endl;
	else
		phoneBook.ShowContact(index - 1);
}

int	main(void)
{
	PhoneBook phoneBook;
	std::string input = "";
	Menu menu;

	menu = MAIN;
	std::cout << "\033[2J\033[1;1H";
	ShowWelcome();
	ShowControls(menu);
	// phoneBook.FillContacts();
	while (1)
	{
		std::getline(std::cin, input);
		if (input.empty())
			continue ;
		else if (input.compare("EXIT") == 0)
			break ;
		if (menu == MAIN)
			HandleMain(phoneBook, menu, input);
		else
			HandleShow(phoneBook, menu, input);
		ShowControls(menu);
	}
}
