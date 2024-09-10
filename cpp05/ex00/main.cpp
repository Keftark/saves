/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:26:50 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/24 14:28:15 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Henri", 1);
	std::cout << a << std::endl;
	try
	{
		a.addGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.msg() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.msg() << std::endl;
	}
}
