/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:26:50 by cpothin           #+#    #+#             */
/*   Updated: 2024/02/19 08:56:43 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
	{
        Bureaucrat bureaucrat("Ash", 11);
        Form form("formName", 10, 5);
        std::cout << form << std::endl;
        form.beSigned(bureaucrat);
    }
	catch (std::exception &e)
	{
        std::cout << RED << e.what() << RESET << std::endl;
    }
    return EXIT_SUCCESS;
}
