/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:48:01 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/26 17:09:11 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
AForm( "Shrubbery Creation Form", 145, 137 ), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
AForm( src ), target(src.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &a)
{
    (void)a;
    return *this;
}

void    ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
    if (this->getSigned() == false)
        throw AForm::NotSignedException();
    else if (bureaucrat.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
		
    std::ofstream file((this->getName() + "_shrubbery").c_str());                                                                                                                                                                                   
	file << "                                                                                                   ░░                                                                                 " << std::endl;
	file << "                                                             ░░░░░░░░          ░░        ░░        ░░                  ░░                                                             " << std::endl;
	file << "                                                               ▒▒▒▒▒▒░░░░░░░░░░░░▒▒░░░░░░░░▒▒░░░░░░░░                ░░░░░░    ░░                                                     " << std::endl;
	file << "                                                       ░░░░▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒░░░░▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░  ░░      ░░▒▒░░░░░░  ░░                                                   " << std::endl;
	file << "                                                       ▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒░░▒▒▒▒▒▒░░▒▒▒▒░░▒▒░░▒▒░░▒▒░░░░░░░░░░    ░░░░░░░░░░░░░░                                                   " << std::endl;
	file << "                                                         ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░                                                 " << std::endl;
	file << "                                                         ▒▒▓▓▓▓▒▒▓▓▓▓▒▒▓▓▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒░░    ░░                                           " << std::endl;
	file << "                                                         ▒▒▓▓▒▒▒▒░░▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒░░░░░░░░                                         " << std::endl;
	file << "                                                       ░░▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▒▒▒▒░░▒▒▒▒▒▒▒▒░░░░                                           " << std::endl;
	file << "                                             ░░░░    ▒▒▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▒▒░░                                           " << std::endl;
	file << "                                             ░░  ░░░░▒▒▒▒▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▒▒▒▒░░░░░░░░▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒░░  ░░░░  ░░                                 " << std::endl;
	file << "                                               ░░▒▒▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▒▒▓▓▒▒▓▓░░░░▒▒▒▒▒▒▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▓▓▒▒▒▒▒▒░░▒▒░░▒▒▒▒░░                             " << std::endl;
	file << "                                     ░░░░      ░░▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▒▒▒▒░░                           " << std::endl;
	file << "                               ░░░░░░▒▒░░░░    ░░▒▒  ▒▒▓▓░░▒▒░░▓▓▒▒▓▓▓▓▒▒▒▒░░░░▓▓▒▒▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒░░▓▓▓▓▒▒▒▒▓▓░░░░▒▒▓▓▓▓▓▓▒▒░░▒▒░░▒▒░░░░▒▒▒▒▒▒▒▒░░░░                         " << std::endl;
	file << "                               ░░▒▒▒▒░░░░░░░░░░░░░░  ▒▒░░░░▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▓▓▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓██▓▓██▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▒▒░░░░  ▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▓▓▒▒▒▒░░                       " << std::endl;
	file << "                           ░░▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒░░░░░░▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░░░░░▒▒░░                     " << std::endl;
	file << "                         ░░▓▓▓▓▓▓▒▒▓▓░░▒▒▒▒▒▒░░░░░░▒▒▒▒▒▒▓▓░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒░░▒▒▒▒▓▓▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒░░                       " << std::endl;
	file << "                         ░░▓▓▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░▒▒▓▓▓▓▒▒░░▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓    ░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░░░░░                   " << std::endl;
	file << "                         ▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░▒▒▓▓▒▒▓▓▓▓▒▒▓▓░░▒▒▒▒▒▒▓▓▒▒▒▒▓▓▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▒▒░░░░░░░░░░▒▒▒▒  ▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░                 " << std::endl;
	file << "                       ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓██▓▓██▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒▒▒▓▓░░░░░░▒▒░░▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒               " << std::endl;
	file << "                       ░░▓▓▒▒▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒████▒▒▒▒▓▓░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▒▒▒▒▒▒▒▒▓▓▒▒▓▓▒▒▓▓▒▒▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒░░▒▒░░░░               " << std::endl;
	file << "                       ▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓░░▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▒▒▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓░░▓▓▓▓▓▓▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒░░               " << std::endl;
	file << "                     ░░▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▒▒▓▓▒▒░░▒▒  ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓██▓▓████▓▓▓▓▒▒░░▒▒▓▓▓▓▓▓▓▓▒▒▓▓██▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒                 " << std::endl;
	file << "                 ░░▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒░░░░▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▒▒▓▓▓▓██▓▓██▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▒▒▓▓▒▒▒▒▓▓▒▒░░                 " << std::endl;
	file << "                 ░░▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓░░▒▒░░▒▒▓▓▓▓▒▒▓▓▓▓░░▓▓▒▒▒▒░░                 " << std::endl;
	file << "                   ▓▓▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓██▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▓▓▒▒▒▒▓▓▓▓▓▓██▓▓▓▓▓▓██▓▓▓▓██████▓▓▓▓▒▒▓▓▓▓▓▓▓▓░░▒▒▓▓▓▓▒▒▒▒▓▓▒▒▓▓▒▒▒▒▒▒▒▒░░                 " << std::endl;
	file << "               ░░▒▒▓▓▓▓▓▓░░▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓████▓▓▒▒▓▓▓▓▓▓████▓▓▒▒▒▒▓▓▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▒▒░░▒▒▒▒▒▒▓▓▒▒▒▒▒▒░░▒▒                 " << std::endl;
	file << "               ▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓████▓▓▓▓▓▓██▒▒▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒░░▒▒░░▒▒▒▒▓▓▓▓░░░░▒▒░░                 " << std::endl;
	file << "                 ▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒▓▓▒▒▓▓▓▓▒▒▓▓▒▒▓▓▒▒▒▒▓▓▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒░░▒▒▒▒▒▒░░▒▒▒▒▒▒                 " << std::endl;
	file << "               ▒▒▓▓▓▓▓▓▒▒▓▓▒▒▒▒░░░░▓▓▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒░░▒▒                       " << std::endl;
	file << "               ▓▓▓▓░░▓▓▒▒░░▒▒░░░░░░▓▓▒▒░░▓▓▒▒▓▓▒▒▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▒▒▓▓▒▒▓▓▓▓▓▓██▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▓▓░░░░▒▒▒▒                     " << std::endl;
	file << "               ░░  ▒▒░░▒▒░░░░▓▓▒▒  ▒▒░░  ░░░░▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██████▓▓▓▓▓▓░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░██▓▓▓▓██████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓▒▒▒▒▓▓▒▒  ░░░░                     " << std::endl;
	file << "                   ▒▒░░▒▒              ▒▒▒▒▒▒▓▓▒▒▓▓▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░▓▓████▓▓▓▓▒▒▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒░░▒▒▒▒▒▒▒▒                           " << std::endl;
	file << "                               ░░▓▓▓▓▒▒▒▒▒▒▓▓░░▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓░░████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓░░░░░░░░░░                         " << std::endl;
	file << "                               ▒▒░░░░░░▒▒▒▒▓▓░░▓▓▒▒▓▓░░▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▓▓▓▓▒▒██████▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░░░                           " << std::endl;
	file << "                             ░░░░▒▒▓▓▒▒▒▒▒▒▓▓▒▒▓▓▓▓░░  ▒▒░░▓▓▓▓▒▒▓▓▓▓▒▒▒▒▓▓▓▓▒▒▒▒▓▓▒▒▓▓██▓▓▓▓▓▓▓▓▓▓░░▒▒████  ▓▓██▓▓▓▓▓▓▓▓▓▓▓▓██▒▒░░▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▒▒▒▒░░                             " << std::endl;
	file << "                           ░░▒▒▒▒░░▒▒▓▓▓▓▒▒▒▒▓▓▓▓▒▒▓▓░░▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓████▒▒  ████░░  ▓▓██▓▓░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒  ▒▒▒▒▓▓▒▒▓▓▒▒▓▓▒▒▒▒▒▒░░  ░░                         " << std::endl;
	file << "                             ▓▓▒▒░░▒▒▒▒▒▒▒▒▓▓░░▒▒░░    ▒▒▓▓▓▓▒▒▓▓▓▓░░▒▒░░▓▓▒▒▓▓▓▓▓▓▒▒▓▓████████▒▒░░▓▓██▓▓▓▓▓▓    ▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▓▓▓▓░░░░▒▒▒▒░░▒▒                           " << std::endl;
	file << "                           ▒▒▒▒▓▓░░░░░░▒▒▓▓▒▒▒▒▓▓▒▒    ▒▒▓▓▒▒▒▒▒▒▓▓▒▒░░▒▒▓▓▒▒▓▓▓▓▒▒▒▒░░▓▓██████░░▒▒████▒▒▓▓▓▓▒▒░░░░░░▒▒▓▓▓▓▓▓▒▒▓▓▓▓▓▓▒▒▓▓▒▒░░  ░░░░▒▒░░  ▒▒░░░░                       " << std::endl;
	file << "                           ▒▒▒▒▒▒  ░░░░  ▒▒▒▒▒▒          ▒▒▒▒▓▓░░▒▒▒▒  ▒▒▒▒░░▒▒▒▒░░    ▒▒██████▒▒▓▓▓▓▓▓▒▒▓▓▓▓░░░░▒▒  ▓▓▓▓    ░░▒▒░░▒▒▓▓▓▓░░  ░░▓▓░░░░░░                               " << std::endl;
	file << "                         ░░        ░░  ▒▒░░░░░░      ░░▒▒▓▓▒▒▒▒░░░░░░░░▓▓▓▓▒▒▓▓▒▒▓▓░░  ▒▒▒▒████████▒▒░░▓▓░░  ░░      ░░░░        ░░  ▒▒▒▒          ░░░░                               " << std::endl;
	file << "                                 ▒▒░░░░░░          ░░▒▒░░▒▒▒▒▒▒▒▒▒▒    ▒▒▓▓░░▓▓▓▓▓▓▒▒  ▒▒░░██████▓▓▒▒▓▓▒▒▒▒░░                        ░░▒▒          ▒▒                                 " << std::endl;
	file << "                                   ▒▒                ░░▓▓▒▒░░          ▓▓▓▓▓▓▓▓▒▒▓▓  ░░▒▒██████▓▓▓▓▓▓▒▒▒▒▒▒▒▒                          ░░            ░░                               " << std::endl;
	file << "                                 ░░░░                ░░▓▓░░░░        ░░▒▒▓▓██▓▓▓▓▒▒▓▓▓▓████████▓▓▓▓▓▓▓▓░░▓▓▒▒░░░░                                                                     " << std::endl;
	file << "                                                         ░░░░▒▒░░      ▓▓██▓▓██▒▒▓▓▒▒████▓▓██▒▒▓▓▓▓▓▓▓▓▒▒▓▓▒▒░░▒▒                                                                     " << std::endl;
	file << "                                                             ░░░░    ▒▒▒▒▓▓▓▓▓▓▓▓▓▓░░████████░░▓▓▓▓▓▓▓▓▓▓░░▓▓▒▒▓▓▒▒                                                                   " << std::endl;
	file << "                                                               ░░  ░░░░▓▓▓▓▓▓▓▓▒▒▓▓▓▓██████▓▓░░▓▓▓▓▓▓░░▒▒▓▓░░▓▓▓▓▒▒                                                                   " << std::endl;
	file << "                                                                   ░░  ▓▓▓▓▒▒░░▒▒▒▒▒▒████▓▓██░░▒▒▓▓▒▒▒▒▒▒▓▓░░▒▒▓▓▓▓░░                                                                 " << std::endl;
	file << "                                                                       ▒▒▒▒  ░░░░▒▒▓▓████░░▒▒░░▒▒░░▓▓▓▓░░░░░░░░▒▒▒▒░░                                                                 " << std::endl;
	file << "                                                                     ░░░░          ▓▓▓▓██▒▒░░        ▓▓        ░░                                                                     " << std::endl;
	file << "                                                                       ░░          ██▓▓██                ░░  ░░░░                                                                     " << std::endl;
	file << "                                                                       ░░          ██▓▓▓▓                                                                                             " << std::endl;
	file << "                                                                                   ██▓▓▓▓                                                                                             " << std::endl;
	file << "                                                                                   ██▓▓▓▓                                                                                             " << std::endl;
	file << "                                                                                   ██▓▓▓▓▒▒        ░░                                                                                 " << std::endl;
	file << "   ░░░░░░░░░░░░░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒████▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░  ░░  ░░                            ░░░░                     " << std::endl;
	file << " ░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░░░░░░░░░ " << std::endl;
	file << " ░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ " << std::endl;

    // file << "                      ___" << std::endl;
    // file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
    // file << "             ,-'          __,,-- \\" << std::endl;
    // file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
    // file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
    // file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
    // file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    // file << "     (     ,-'                  `." << std::endl;
    // file << "      `._,'     _   _             ;" << std::endl;
    // file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    // file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
    // file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
    // file << "                \"Hb HH dF" << std::endl;
    // file << "                 \"HbHHdF" << std::endl;
    // file << "                  |HHHF" << std::endl;
    // file << "                  |HHH|" << std::endl;
    // file << "                  |HHH|" << std::endl;
    // file << "                  |HHH|" << std::endl;
    // file << "                  |HHH|" << std::endl;
    // file << "                  dHHHb" << std::endl;
    // file << "                .dFd|bHb.               o" << std::endl;
    // file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
    // file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
    // file << "##########################################" << std::endl;
    file.close();
}