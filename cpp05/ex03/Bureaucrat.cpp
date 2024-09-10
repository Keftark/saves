/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:03:27 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/26 10:12:54 by cpothin          ###   ########.fr       */
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
    o << a.getName() << ", bureaucrat grade " << a.getGrade();
    return (o);
}

void    Bureaucrat::signForm(AForm &form)
{
    try
	{
        form.beSigned(*this);
        std::cout << CYAN << *this << ToColor((" signed " + form.getName()).c_str(), Colors::RoyalBlue, Colors::Green) << std::endl;
    }
	catch (AForm::GradeTooLowException &e)
	{
        std::cout << ToColor((name + " coulnd't sign " + form.getName() + " because " + e.what()).c_str(), Colors::Red, Colors::DeepPink) << std::endl;
    }
}

void    Bureaucrat::executeForm(const AForm &form) const
{
    try
	{
        form.execute(*this);
    }
	catch (std::exception &e)
	{
        std::cout << ToColor((name + " couldn't execute " + form.getName() + " because " + e.what()).c_str(), Colors::Red, Colors::DeepPink) << std::endl;
    }
}
