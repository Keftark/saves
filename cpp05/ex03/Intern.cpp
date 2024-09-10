/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:19:36 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/26 11:50:58 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &a)
{
	if (this != &a)
		*this = a;
}

Intern &Intern::operator=(const Intern &a)
{
	(void)a;
	return (*this);
}

AForm *RobotomyRequest(const std::string &formName)
{
	return (new RobotomyRequestForm(formName));
}
AForm *PresidentialPardon(const std::string &formName)
{
	return (new PresidentialPardonForm(formName));
}
AForm *ShrubberyCreation(const std::string &formName)
{
	return (new ShrubberyCreationForm(formName));
}

AForm *Intern::makeForm(std::string formName, std::string targetName)
{
	AForm *newForm = NULL;
	std::string formNames[] = 
	{
		"robotomy",
		"presidential",
		"shrubbery"
	};
	AForm* (*forms[])(std::string const &) = 
	{
		RobotomyRequest,
		PresidentialPardon,
		ShrubberyCreation
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			newForm = forms[i](targetName);
			std::cout << ToColor(("Intern creates " + formName + "!").c_str(), Colors::Cyan, Colors::Blue) << std::endl;
			return (newForm);
		}
	}
	std::cout << RGB2(Colors::Red, Colors::Black) << "It seems that this form name doesn't exist..." << RESET << std::endl;
	return (NULL);
}