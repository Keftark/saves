/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:03:27 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/24 15:26:53 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& newName, int newGrade) : name(newName), grade(newGrade)
{
	if (grade > 150)
		throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
	std::cout << LIGHTTEAL << this->name << RESET << Rainbow(" is created.") << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RGB2(Colors::Red, Colors::Black) << this->name << " died at the office." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &a) : name(a.name), grade(a.grade)
{
	*this = a;
	std::cout << "A clone named " << TEAL << this->getName() << RESET << Rainbow(" is created.") << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &a)
{
    if (this != &a)
        this->grade = a.getGrade();
    return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::addGrade()
{
	if (this->grade - 1 < 1)
		throw (GradeTooHighException());
	this->grade--;
}

void Bureaucrat::subGrade()
{
	if (this->grade + 1 > 150)
		throw (GradeTooLowException());
	this->grade++;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &a)
{
    o << ToColor(a.getName(), Colors::Yellow, Colors::Orange)
	<< ToColor(", bureaucrat grade ", Colors::Orange, Colors::Magenta) << RGB(Colors::Magenta) << a.getGrade() << RESET << ".";
    return (o);
}
