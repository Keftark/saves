/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:26:50 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/26 12:04:57 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int main( void )
{
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy", "Bender");
    delete (rrf);
    rrf = someRandomIntern.makeForm("wrong name", "Bender");
    rrf = someRandomIntern.makeForm("presidential", "Bender");
    delete (rrf);
}
