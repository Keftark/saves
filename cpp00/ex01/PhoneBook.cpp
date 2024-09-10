/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:02:19 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/27 10:43:49 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{
	
}

void PhoneBook::FillContacts(void)
{
	contacts[0].AddContact("Jean", "Yves", "Jeannot", "0123456789", "Aime le cake aux fruits");
	contacts[1].AddContact("Jean", "Yves", "Jeannot", "0123456789", "Aime le cake aux fruits");
	contacts[2].AddContact("Jean", "Yves", "Jeannot", "0123456789", "Aime le cake aux fruits");
	contacts[3].AddContact("Jean", "Yves", "Jeannot", "0123456789", "Aime le cake aux fruits");
	contacts[4].AddContact("Jean", "Yves", "Jeannot", "0123456789", "Aime le cake aux fruits");
	contacts[5].AddContact("Jean", "Yves", "Jeannot", "0123456789", "Aime le cake aux fruits");
	contacts[6].AddContact("Jean", "Yves", "Jeannot", "0123456789", "Aime le cake aux fruits");
	contacts[7].AddContact("Jean", "Yves", "Jeannot", "0123456789", "Aime le cake aux fruits");
}

void PhoneBook::AddContact(void)
{
	static int i;

	contacts[i].NewContact();
	if (++i == 8)
		i = 0;
}

int PhoneBook::ShowContacts(void)
{
	if (contacts[0].Exists() == 0)
	{
		std::cout << "\033[1;31mThere is no contact yet!\033[0;37m\nAdd one using the \033[0;34mADD\033[0;37m command."
		<< std::endl << std::endl;
		return (0);
	}
	std::cout << "-------------------\033[0;34mCONTACTS\033[0;37m------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First name";
	std::cout << "|" << std::setw(10) << "Last name";
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++)
		contacts[i].ShowContactInList(i);
	std::cout << "---------------------------------------------" << std::endl << std::endl;
	return (1);
}

void PhoneBook::ShowContact(int i)
{
	if (contacts[i].Exists() == 0)
	{
		std::cout << std::endl
		<< "\033[1;31mThis contact does not exist!\033[0;37m\nPlease select another one."
		<< std::endl << std::endl;
		return ;
	}
	contacts[i].ShowContact();
}