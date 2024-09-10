/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:02:13 by cpothin           #+#    #+#             */
/*   Updated: 2023/12/27 10:28:53 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <sstream>

class PhoneBook
{
	Contact contacts[8];
	private:

	public:
		PhoneBook();
		~PhoneBook();
		void 	AddContact(void);
		void 	ShowContact(int i);
		int		ShowContacts(void);
		void	FillContacts(void);
};

#endif