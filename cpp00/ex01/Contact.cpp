/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:35:36 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/27 11:08:29 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	
}

Contact::~Contact()
{
	
}

std::string Contact::GetInput(std::string str) const
{
	std::string input = "";

	std::cout << str << std::endl;
	std::cout << "\033[2;36m>\033[0;37m ";
	while (input.empty())
		std::getline(std::cin, input);
	return (input);
}

void Contact::AddContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

void Contact::NewContact(void)
{
	this->firstName = this->GetInput("\033[2;37mEnter your first name?\033[0;37m");
	this->lastName = this->GetInput("\033[2;37mEnter your last name?\033[0;37m");
	this->nickname = this->GetInput("\033[2;37mEnter your nickname?\033[0;37m");
	this->phoneNumber = this->GetInput("\033[2;37mWhat is your phone number?\033[0;37m");
	this->darkestSecret = this->GetInput("\033[2;37mWhat is your darkest secret?\033[0;37m");
	std::cout << std::endl << "\033[0;32mContact added!\033[0;37m" << std::endl << std::endl;
}

std::string Contact::ShowStr(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void Contact::ShowContactInList(int index)
{
	std::cout << "|" << std::setw(10) << index + 1;
	std::cout << "|" << std::setw(10) << this->ShowStr(this->firstName);
	std::cout << "|" << std::setw(10) << this->ShowStr(this->lastName);
	std::cout << "|" << std::setw(10) << this->ShowStr(this->nickname) << "|";
	std::cout << std::endl;
}

void Contact::ShowContact(void)
{
	std::cout << std::endl << "\033[0;36mFirst name:\033[0;37m " << this->firstName << std::endl;
	std::cout << "\033[0;36mLast name:\033[0;37m " << this->lastName << std::endl;
	std::cout << "\033[0;36mNickname:\033[0;37m " << this->nickname << std::endl;
	std::cout << "\033[0;36mPhone number:\033[0;37m " << this->phoneNumber << std::endl;
	std::cout << "\033[0;36mDarkest secret:\033[0;37m " << this->darkestSecret << std::endl << std::endl;
}

bool Contact::Exists(void)
{
	if (this->firstName.compare("") == 0 || this->firstName.empty())
		return (false);
	return (true);
}