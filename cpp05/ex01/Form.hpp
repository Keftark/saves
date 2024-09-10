/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:49:23 by cpothin           #+#    #+#             */
/*   Updated: 2024/01/25 15:22:55 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int requiredGradeToSign;
		const int requiredGradeToExecute;
	public:
		Form(const std::string& newName, int newGradeToSign, int newGradeToExecute);
		~Form();
		Form(const Form &a);
    	Form &operator=(const Form &a);
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {return "Form grade is too high";}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {return "Form grade is too low";}
		};
};
std::ostream &operator<<(std::ostream &o, const Form &a);

#endif