/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:46:09 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/26 11:52:11 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& newName, int newGradeToSign, int newGradeToExecute) : 
name(newName), 
requiredGradeToSign(newGradeToSign), 
requiredGradeToExecute(newGradeToExecute)
{
	if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
		throw (GradeTooLowException());
	else if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
		throw (GradeTooHighException());
	std::cout << Rainbow((this->name + " is created.").c_str()) << std::endl;
}

AForm::~AForm()
{
	std::cout << RGB2(Colors::Red, Colors::Black) << "The " << this->getName() << " is destroyed." << RESET << std::endl;
}

AForm::AForm(const AForm &a) : 
name(a.name), 
requiredGradeToSign(a.requiredGradeToSign), 
requiredGradeToExecute(a.requiredGradeToExecute)
{
	*this = a;
	std::cout << Rainbow(("A form clone named " + this->getName() + " is created.").c_str()) << std::endl;
}

AForm &AForm::operator=(const AForm &a)
{
    if (this != &a)
		this->isSigned = a.isSigned;
    return (*this);
}

std::string AForm::getName() const
{
	return (this->name);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->requiredGradeToSign)
	{
		std::cout << ToColor((bureaucrat.getName() + " couldn't sign the " + this->getName() + " form because his grade is too low.").c_str(), Colors::Magenta, Colors::RoyalBlue) << std::endl;
        throw AForm::GradeTooLowException();
	}
	std::cout << ToColor((bureaucrat.getName() + " signed the " + this->getName() + " form.").c_str(), Colors::Magenta, Colors::RoyalBlue) << std::endl;
    this->isSigned = true;
}

int AForm::getGradeToSign() const
{
	return (this->requiredGradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->requiredGradeToExecute);
}

bool AForm::getSigned() const
{
	return (this->isSigned);
}

std::ostream &operator<<(std::ostream &o, const AForm &a)
{
    o << std::endl
	<< ToColor("---------------------------------", Colors::Magenta, Colors::Orange)
	<< std::endl << ROSERED << "Form: " << std::endl << std::endl << ToColor(a.getName(), Colors::Yellow, Colors::Orange) << std::endl
	<< ToColor("- required grade to sign: ", Colors::Orange, Colors::Magenta) << RGB(Colors::Magenta) << a.getGradeToSign() << RESET << std::endl
	<< ToColor("- required grade to execute: ", Colors::Orange, Colors::Magenta) << RGB(Colors::Magenta) << a.getGradeToExecute() << RESET << std::endl
	<< ToColor("---------------------------------", Colors::Magenta, Colors::Orange)
	<< std::endl;
    return (o);
}