/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:48:59 by cpothin           #+#    #+#             */
/*   Updated: 2024/02/19 08:57:09 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& newName, int newGradeToSign, int newGradeToExecute) : 
name(newName), 
requiredGradeToSign(newGradeToSign), 
requiredGradeToExecute(newGradeToExecute)
{
	if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
		throw (GradeTooLowException());
	else if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
		throw (GradeTooHighException());
	std::cout << LIGHTTEAL << this->name << RESET << Rainbow(" is created.") << std::endl;
}

Form::~Form()
{
	std::cout << RGB2(Colors::Red, Colors::Black) << "The " << this->getName() << " is destroyed." << RESET << std::endl;
}

Form::Form(const Form &a) : 
name(a.name), 
requiredGradeToSign(a.requiredGradeToSign), 
requiredGradeToExecute(a.requiredGradeToExecute)
{
	*this = a;
	std::cout << "A form clone named " << TEAL << this->getName() << RESET << Rainbow(" is created.") << std::endl;
}

Form &Form::operator=(const Form &a)
{
    if (this != &a)
		this->isSigned = a.isSigned;
    return (*this);
}

std::string Form::getName() const
{
	return (this->name);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->requiredGradeToSign)
	{
		std::cout << RED << bureaucrat.getName() << " couldn't sign the " << this->getName() << " form because his grade is too low." << RESET << std::endl;
        throw Form::GradeTooLowException();
	}
	std::cout << bureaucrat.getName() << " signed the " << this->getName() << " form." << std::endl;
    this->isSigned = true;
}

int Form::getGradeToSign() const
{
	return (this->requiredGradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->requiredGradeToExecute);
}

std::ostream &operator<<(std::ostream &o, const Form &a)
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