/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:18:10 by cpothin           #+#    #+#             */
/*   Updated: 2024/02/16 16:43:56 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
AForm(src), target(src.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &a)
{
    (void)a;
    return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
    if (bureaucrat.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else 
    {
        static int i;
        if (i % 2 == 0)
            std::cout << ToColor(("BZZZZZT! " +this->target + " has been robotomized!").c_str(), Colors::Green, Colors::RoyalBlue) << std::endl;
        else
            std::cout << ToColor(("Robotomy failed! " + this->target + " is still alive.").c_str(), Colors::Red, Colors::DeepPink) << std::endl;
        i++;
    }
}