/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:35:52 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/27 10:28:18 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
		std::string ShowStr(std::string str);
		std::string GetInput(std::string str) const;
	public:
		Contact();
		~Contact();
		void NewContact(void);
		void ShowContactInList(int index);
		void ShowContact(void);
		bool Exists(void);
		void AddContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);

};

#endif