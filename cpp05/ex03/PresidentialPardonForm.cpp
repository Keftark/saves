/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:19:37 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/26 17:09:16 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
AForm("Presidential Pardon Form", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
AForm(src), target(src.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &a)
{
    (void)a;
    return *this;
}

void    PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
    if (bureaucrat.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
        std::cout << ToColor((this->target + " has been pardoned by Zaphod Beeblebrox.").c_str(), Colors::Gold, Colors::Yellow) << std::endl;
}